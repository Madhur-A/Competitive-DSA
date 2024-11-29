



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    using element = std::tuple<int, int, int>;
    using p_queue = std::priority_queue<element, std::vector<element>, std::greater<element>>;
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        std::vector<std::vector<bool>> visited(r+1, std::vector<bool>(c+1));
        p_queue t;
        t.push({0, 0, 0});
        while(not t.empty()) {
            int const z = t.size();
            for(int l = 0; l < z; ++l) {
                std::tuple<int, int, int> p = t.top(); t.pop();
                int const x = std::get<1>(p), y = std::get<2>(p);
                int const curr_steps = std::get<0>(p);
                if(x == r-1 and y == c-1) {  return curr_steps; }
                if(not visited[x][y]) {
                    visited[x][y] = true;
                    for(direction const &dir: dirs) {
                        int const h = dir.first, k = dir.second;
                        if(x + h >= 0 and y + k >= 0 and x + h < r and y + k < c and not visited[x + h][y + k]) {
                            t.push({curr_steps + grid[x + h][y + k], x + h, y + k});
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid = {{0,1,1},{1,1,0},{1,1,0}};
    std::fprintf(stdout, "%d\n", sol.minimumObstacles(grid));


    return 0;
}
