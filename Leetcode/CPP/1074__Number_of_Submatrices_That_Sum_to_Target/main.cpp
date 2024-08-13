



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> dp;
public:
    int numSubmatrixSumTarget(vector<vector<int>>& grid, int target) {
        int const r = grid.size(), c = grid[0].size();
        int ans = 0;

        for(int i = 0; i < r; ++i) {
            for(int j = 1; j < c; ++j) {
                grid[i][j] += grid[i][j - 1];
            }
        }

        for(int j = 0; j < c; ++j) {
            for(int k = j; k < c; ++k) {
                dp.clear();
                dp[0] = 1;
                int sum = 0;
                for(int i = 0; i < r; ++i) {
                    sum += grid[i][k] - (j ? grid[i][j - 1] : 0);
                    ans += (dp.count(sum - target)) ? dp[sum - target] : 0;
                    dp[sum] += 1;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid = {{0,1,0},{1,1,1},{0,1,0}};
    int target = 0;    
    std::fprintf(stdout, "%d\n", sol.numSubmatrixSumTarget(grid, target));


    return 0;
}
