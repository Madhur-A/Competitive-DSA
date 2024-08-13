



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int dp[16][65536];
public:
    int dfs(std::vector<int> const &nums, int const &n, int mask, int k) {
        if(k >= n+1)    { return 0; }
        if(dp[k][mask]) { return dp[k][mask]; }

        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                int const new_mask = (1 << i) | (1 << j);
                if((mask & new_mask) == 0) {
                    dp[k][mask] = std::max(
                        dp[k][mask],
                        k * std::gcd(nums[i], nums[j]) + dfs(nums, n, mask | new_mask, k + 1)
                    );
                }
            }
        }

        return dp[k][mask];
    }

    int maxScore(vector<int>& nums) {
        int const n = nums.size();
        memset(dp, 0, sizeof(dp));
        return dfs(nums, n, 0, 1);
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1,2};    
    std::fprintf(stdout, "%d\n", sol.maxScore(nums));


    return 0;
}
