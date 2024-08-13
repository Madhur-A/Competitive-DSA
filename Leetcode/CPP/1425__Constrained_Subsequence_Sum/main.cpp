



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::deque<int> t;
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int const n = nums.size();
        std::vector<int> dp(n);
        for(int i = 0; i < n; ++i) {
            while(not t.empty() and i > k + t.front()) { t.pop_front(); }
            dp[i] = t.empty() ? nums[i] : nums[i] + std::max(0, dp[t.front()]);
            while(not t.empty() and dp[t.back()] <= dp[i]) { t.pop_back(); }
            t.push_back(i);
        }
        return std::ranges::max(dp);
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {10,2,-10,5,20};
    int k = 2;
    std::fprintf(stdout, "%d\n", sol.constrainedSubsetSum(nums, k));

    return 0;
}

