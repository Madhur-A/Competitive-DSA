



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::vector<int> dp;
public:
    int find_next(vector<int>& nums, long long target) {
        int left = 0, right = nums.size(), mid = 0;
        if(target > nums[right - 1]) { return -1; }
        while(left < right) {
            mid = left + ((right - left) >> 1);
            if(nums[mid] == target) { return mid; }
            if(nums[mid]  < target) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }

        return -1;
    }

    int longestSquareStreak(vector<int>& nums) {
        int const n = nums.size();
        std::ranges::sort(nums);
        dp.resize(n,  1);
        int res = -1, i = 0;

        while(nums[i] * 1LL * nums[i] <= nums.back()) {
            long long const target = nums[i] * 1LL * nums[i];
            int const next_index = find_next(nums, target);
            if(next_index != -1) {
                dp[next_index] = std::max(dp[next_index], dp[i] + 1);
                res = std::max(dp[next_index], res);
            }
            i += 1;
        }


        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {4,3,6,16,8,2};

    return std::fprintf(stdout, "%d\n", sol.longestSquareStreak(nums));
}
