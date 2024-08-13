



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> seen;
public:
    int countSubarrays(vector<int>& nums, int k) {
        int const n = nums.size();
        int const index = std::ranges::find(nums, k) - nums.begin();

        int res = 0;
        for(int i = index+1, count = 0; i < n; ++i) { // rhs = (nums[index], nums[n-1]]
            count += (nums[i] > k) ? 1 : -1;
            res += (count >= 0 and count <= 1);
            seen[n+count] += 1;
        }

        for(int i = index-1, count = 0; i >= 0; --i) {
            count += (nums[i] > k) ? 1 : -1;
            res += (count >= 0 and count <= 1);
            res += seen[n-count] + seen[n-count+1];
        }

        return res + 1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {3,2,1,4,5};
    int k = 4;
    std::fprintf(stdout, "%d\n", sol.countSubarrays(nums, k));

    return 0;
}
