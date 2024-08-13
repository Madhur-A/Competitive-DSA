



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    inline static constexpr int const mod = 1'000'000'007;
public:
    std::vector<std::vector<long>> dp;
public:
    int rx(std::vector<int> &nums) {
        int const n = nums.size();
        if(n >= 2) {
            std::vector<int> left, right;
            int const root = nums[0];
            for(int const num: nums) {
                if(num < root) {  left.push_back(num); }
                if(num > root) { right.push_back(num); }
            }
            int const ls = left.size();
            return ((dp[n-1][ls] * 1LL * rx(left)) % mod * rx(right)) % mod;
        }
        return 1;
    }

    int numOfWays(vector<int>& nums) {
        int const n = nums.size();
        dp.resize(n+1);
        for(int i = 0; i < n + 1; ++i) {
            dp[i] = std::vector<long>(i+1, 1);
            for(int j = 1; j < i; ++j) {
                dp[i][j] = (dp[i-1][j-1] + 0L + dp[i-1][j]) % mod;
            }
        }
        return rx(nums) - 1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {3,4,5,2,1};
    std::fprintf(stdout, "%d\n", sol.numOfWays(nums));

    return 0;
}
