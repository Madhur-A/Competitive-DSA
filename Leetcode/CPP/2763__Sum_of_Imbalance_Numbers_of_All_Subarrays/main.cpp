



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::vector<int> left, right;
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int const n = nums.size();
        int res = 0;
        left.resize(n);
        right.resize(n + 2, -1);
        for(int i = 0; i < n; ++i) {
            left[i] = std::max(right[nums[i] + 1], right[nums[i]]);
            right[nums[i]] = i;
        }
        right.assign(n + 2, n);
        for (int i = n - 1; i >= 0; --i) {
            right[nums[i]] = i;
            res += (i - left[i]) * (right[nums[i] + 1] - i);
        }
        return res - n * (n + 1) / 2;
    }
};


int main() {
    std::vector<int> nums = {2,3,1,4};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.sumImbalanceNumbers(nums));


    return 0;
}
