




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int find_left(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid = 0;
        while(left < right) {
            mid = left + ((right - left) >> 1);
            if(nums[mid] < target) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    bool condition(vector<int>& nums, int mid, int k) {
        int const n = nums.size();
        int res = 0;
        for(int i = 0; i < n; ++i) {
            res += i - find_left(nums, nums[i] - mid);
        }
        return res < k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int const n = nums.size();
        std::ranges::sort(nums);
        int left = 0, right = std::abs(nums[0] - nums[n-1]), mid = 0;
        while(left < right) {
            mid = left + ((right - left) >> 1);
            if(condition(nums, mid, k)) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1,3,1};
    int k = 1;
    std::fprintf(stderr, "%d\n", sol.smallestDistancePair(nums, k));


    return 0;
}

