




#include <bits/stdc++.h>
#include <execution>

using std::vector;

class Solution {
public:
    int dp[10001];
public:
    bool canPartition(vector<int>& nums) {
        int const sum = std::reduce(nums.begin(), nums.end(), 0, std::plus<int>());
                // std::reduce(std::execution::par_unseq, nums.begin(), nums.end(), 0, std::plus<int>());
        if(sum & 1) { return false; }
        int const target = sum / 2;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int const &num: nums) {
            for(int j = target; j > num-1; --j) {
                dp[j] |= dp[j - num];
            }
        }
        return dp[target];
    }
};


int main() {
    Solution sol;
    std::vector<int> nums = {1,5,11,5};
    std::cout.setf(std::ios::boolalpha);
    std::cout << sol.canPartition(nums) << '\n';


    return 0;
}

