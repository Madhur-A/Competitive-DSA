



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    std::vector<int> dp;
public:
    int rx(vector<vector<int>>& grid, int prev, int i, int j) {
        int const r = grid.size(), c = grid[0].size();
        if(dp[i * c + j]) { return dp[i * c + j]; }
        int res = 0;
        if(i >= 0 and j >= 0 and i < r and j < c) {
            for(direction const &dir: dirs) {
                int const h = dir.first + i, k = dir.second + j;
                if(h >= 0 and k >= 0 and h < r and k < c and grid[h][k] < prev) {
                    res = std::max(res, 1 + rx(grid, grid[h][k], h, k));
                }
            }
            return dp[i * c + j] = res;
        }
        return res;
    }

    int longestIncreasingPath(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        dp.resize(r * c + c + 1UL);
        int ans = 0;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(not dp[i * c + j]) {
                    ans = std::max(ans, rx(grid, grid[i][j], i, j));
                }
            }
        }
        return ans + 1;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{9,9,4},{6,6,8},{2,1,1}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.longestIncreasingPath(grid));


    return 0;
}
