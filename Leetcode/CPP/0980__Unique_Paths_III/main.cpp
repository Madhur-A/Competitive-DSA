



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    void rx(vector<vector<int>>& g, vector<vector<bool>>& visited, int nob_count, int res, int &ans, int i, int j) {
        int const r = g.size(), c = g[0].size();
        if(i >= 0 and j >= 0 and i < r and j < c and not visited[i][j] and (g[i][j] == 0 or g[i][j] == 2)) {
            if(g[i][j] ==  2) {
                ans += ((res-1) == nob_count);
                return;
            }
            for(direction const &dir: dirs) {
                int const h = dir.first + i, k = dir.second + j;
                visited[i][j] = true;
                rx(g, visited, nob_count, res + 1, ans, h, k);
                visited[i][j] = false;
            }
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        int nob_count = 0, res = 0, ans = 0;
        for(std::vector<int> const &row: grid) {
            nob_count += std::ranges::count(row, 0);
        }
        std::vector<std::vector<bool>> visited(r, std::vector<bool>(c));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    rx(grid, visited, nob_count, res, ans, i, j);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};    
    std::fprintf(stdout, "%d\n", sol.uniquePathsIII(grid));


    return 0;
}
