



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
    inline static constexpr int       const     mod = 1'000'000'007;
public:
    std::vector<int> dp;
public:
    int rx(vector<vector<int>>& g, int prev, int i, int j) {
        int const r = g.size(), c = g[0].size();
        long long res = 1;
        if(i >= 0 and j >= 0 and i < r and j < c and g[i][j] > prev) {
            if(dp[i * c + j] != 0) { return dp[i * c + j]; }
            for(direction const &dir: dirs) {
                int const h = dir.first + i, k = dir.second + j;
                res += rx(g, g[i][j], h, k);
                res %= mod;
            }
            return dp[i * c + j] = res;
        }
        return 0;
    }

    int countPaths(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        dp.resize(r * c + c + 1UL);
        long long ans = 0;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                ans += rx(grid, -1, i, j);
                ans %= mod;
            }
        }
        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{1,1},{3,4}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.countPaths(grid));


    return 0;
}
