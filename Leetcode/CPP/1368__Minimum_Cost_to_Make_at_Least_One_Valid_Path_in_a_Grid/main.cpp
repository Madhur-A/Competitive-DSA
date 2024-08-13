



#include <bits/stdc++.h>

using std::vector;


class Solution {
public:
    using direction = std::pair<int, int>;
    using   element = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    std::deque<element> t;
public:
    int minCost(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        std::vector<std::vector<bool>> visited(r, std::vector<bool>(c));

        t.push_back({0, 0});
        while(not t.empty()) {
            int const z = t.size();
            for(int l = 0; l < z; ++l) {
                element const p = t.back(); t.pop_back();
                int const x = p.second / c, y = p.second % c;
                int const f = p.first;
                if(x == r-1 and y == c-1) { return f; }
                if(not visited[x][y]) {
                    visited[x][y] = true;
                    for(int d = 0; d < 4; ++d) {
                        int const h = dirs[d].first + x, k = dirs[d].second + y, move_to = d + 1;
                        if(h >= 0 and k >= 0 and h < r and k < c) {
                            (grid[x][y] == move_to) ? t.push_back({f, h * c + k}) : t.push_front({f + 1, h * c + k});
                        }
                    }
                }
            }
        } return -EXIT_FAILURE;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};    
    std::fprintf(stdout, "%d\n", sol.minCost(grid));


    return 0;
}
