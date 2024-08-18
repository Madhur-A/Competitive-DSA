




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::vector<int> dp;
public:
    bool dfs(vector<int>& nums, int k, int target) {
        int const n = nums.size();
        dp.resize(k);
        std::ranges::sort(nums, std::greater<int>());
        std::function<bool(int)> rx = [&](int index) {
            if(index == n) { return true; }
            for(int j = 0; j < k; ++j) {
                if(j > 0 and dp[j] == dp[j-1]) { continue; }
                dp[j] += nums[index];
                if(dp[j] <= target and rx(index+1)) { return true; }
                dp[j] -= nums[index];
            }
            return false;
        };
        return rx(0);
    }

    bool dp_bit(vector<int>& nums, int target) {
        int const n = nums.size();
        dp.resize(1 << n, -1);
        dp[0] = 0;
        for(int i = 0; i < (1 << n); ++i) {
            if(dp[i] != -1) {
                for(int j = 0; j < n; ++j) {
                    if(not (i & (1 << j)) and dp[i] + nums[j] <= target) {
                        dp[i | (1 << j)] = (dp[i] + nums[j]) % target;
                    }
                }
            }
        }

        return dp.back() == 0;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int const total = std::reduce(nums.begin(), nums.end(), 0);
        int const target = total / k;
        if((total % k) != 0) { return false; }

        return dfs(nums, k, target);
//        return dp_bit(nums, target);
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {4,3,2,3,5,2,1};
    int k = 4;
    std::cout.setf(std::ios::boolalpha);
    std::cout << sol.canPartitionKSubsets(nums, k) << '\n';


    return 0;
}

