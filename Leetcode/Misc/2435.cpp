



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[2] = {{0,1},{1,0}};
    inline static constexpr int       const     mod = 1000000007;
public:
    std::vector<std::vector<std::vector<int>>> dp;
public:
    int dfs(vector<vector<int>>& grid, int k, int i , int j, int curr) {
        int const r = grid.size(), c = grid[0].size();
        if(i >= 0 and j >= 0 and i < r and j < c) {
            if(i == r-1 and j == c-1) { return (curr % k) == 0; }
            if(dp[i][j][curr]  != -1) { return dp[i][j][curr];  }
            int res = 0;
            for(direction const &dir: dirs) {
                int const x = dir.first + i, y = dir.second + j;
                if(x >= 0 and y >= 0 and x < r and y < c) {
                    res = (res + dfs(grid, k, x, y, (curr + grid[x][y]) % k)) % mod;
                }
            }
            return dp[i][j][curr] = res;
        }
        return 0;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int const r = grid.size(), c = grid[0].size();
        dp.resize(r+1, std::vector<std::vector<int>>(c+1, std::vector<int>(k+1, -1)));
        return dfs(grid, k, 0, 0, grid[0][0] % k);
    }
};

int main() {
    Solution *sol = new Solution();
    std::vector<std::vector<int>> grid = {{5,2,4},{3,0,5},{0,7,2}};
    int const k = 3;    
    std::fprintf(stdout, "%d\n", sol->numberOfPaths(grid, k));
    delete sol;


    return 0;
}
