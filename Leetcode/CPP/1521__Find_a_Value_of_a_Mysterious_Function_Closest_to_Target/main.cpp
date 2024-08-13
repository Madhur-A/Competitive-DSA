



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_set<int> prev, curr;
public:
    int closestToTarget(vector<int>& nums, int target) {
        int res = INT_MAX;
        for(int const &num: nums) {
            curr.insert(num);
            for(int const &p_num: prev) { curr.insert(p_num & num); }
            for(int const &c_num: curr) { res = std::min(res, std::abs(c_num - target)); }
            prev = curr;
            curr.clear();
        }
        return res;
    }
};

int main() {
    std::vector<int> nums = {9,12,3,7,15};
    int target = 5;
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.closestToTarget(nums, target));


    return 0;
}
