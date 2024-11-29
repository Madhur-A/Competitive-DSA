



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using element   = std::tuple<int, int, int>; // time, i, j
    using direction = std::pair<int, int>;
public:
    inline static constexpr int       const     inf = 1'000'000'000;
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    std::vector<std::vector<int>> paths;
    std::priority_queue<element, std::vector<element>, std::greater<element>> t;
public:
    int minimumTime(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        int not_possible = 0;
        for(direction const &dir: dirs) {
            int const h = dir.first, k = dir.second;
            if(h >= 0 and k >= 0 and h < r and k < c) {
                not_possible += (grid[h][k] > 1);
            }
        }
        if(not_possible == 2) { return -1; }
        paths.resize(r, std::vector<int>(c, inf));
        paths[0][0] = 0;
        t.push({0, 0, 0});
        int ans = inf;
        while(not t.empty()) {
            element const p = t.top(); t.pop();
            int const time = std::get<0>(p), x = std::get<1>(p), y = std::get<2>(p);
            if(x == r-1 and y == c-1) { return time; }
            for(direction const &dir: dirs) {
                int const h = dir.first + x, k = dir.second + y;
                if(h >= 0 and k >= 0 and h < r and k < c) {
                    int const next_t =
                        (time+1 < grid[h][k]) ? grid[h][k] + ((grid[h][k] - time-1) & 1) : time + 1;
                    if(next_t < paths[h][k]) {
                        paths[h][k] = next_t;
                        t.push({next_t, h, k});
                    }
                }
            }
        } return -1;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid = {{0,1,3,2},{5,1,2,5},{4,3,8,6}};
    std::fprintf(stdout, "%d\n", sol.minimumTime(grid));



    return 0;
}
