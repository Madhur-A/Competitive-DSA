



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    std::vector<std::vector<bool>> visited;
    std::queue<std::pair<int, int>> t;
public:
    int count_islands(vector<vector<int>>& grid) { // (En)forcing BFS, lol!
        int const r = grid.size(), c = grid[0].size();
        visited.clear();
        visited.resize(r, std::vector<bool>(c));
        int islands = 0;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] and not visited[i][j]) {
                    t.push({i, j});
                    islands += 1;
                    while(not t.empty()) {
                        std::pair<int, int> const p = t.front(); t.pop();
                        int const x = p.first, y = p.second;
                        if(not visited[x][y]) {
                            visited[x][y] = true;
                            for(direction const &dir: dirs) {
                                int const h = dir.first + x, k = dir.second + y;
                                if(h >= 0 and k >= 0 and h < r and k < c and not visited[h][k] and grid[h][k]) {
                                    t.push({h, k});
                                }
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        int res = count_islands(grid);
        if(res == 0 or res > 1) { return 0; }
        res = 0;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    res = count_islands(grid);
                    if(res > 1) { return 1; }
                    grid[i][j] = 1;
                }
            }
        }

        return (res == 0) ? 1 : 2;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{0,1,1,0},{0,1,1,0},{0,0,0,0}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minDays(grid));


    return 0;
}
