



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int const n = nums.size();
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1; dp[0][1] = 1;
        int ans = 1;

        for(int i = 1; i < n; ++i) {
            dp[i][0] = (nums[i - 1] > nums[i]) ? 1 + dp[i - 1][1] : 1;
            dp[i][1] = (nums[i - 1] < nums[i]) ? 1 + dp[i - 1][0] : 1;
            ans = std::max(ans, std::max(dp[i][0], dp[i][1]));
        }

        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {9,4,2,10,7,8,8,1,9};
    std::fprintf(stdout, "%d\n", sol.maxTurbulenceSize(nums));


    return 0;
}
