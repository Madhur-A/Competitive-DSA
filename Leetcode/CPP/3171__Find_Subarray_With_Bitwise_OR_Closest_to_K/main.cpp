



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int const n = nums.size();
        int res = INT_MAX;
        for(int i = 0; i < n; ++i) {
            res = std::min(res, std::abs(nums[i] - k));
            for(int j = i-1; j >= 0 and ((nums[j] | nums[i]) != nums[j]); --j) {
                nums[j] = nums[j] | nums[i];
                res = std::min(res, std::abs(nums[j] - k));
                if(res == 0) { return 0; }
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> nums = {1,2,4,5};
    int k = 3;
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minimumDifference(nums, k));

    return 0;
}
