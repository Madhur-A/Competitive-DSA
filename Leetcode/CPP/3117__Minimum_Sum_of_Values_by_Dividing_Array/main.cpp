



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> and_v;
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int const n = nums.size(), m = andValues.size();
        for(int const &val: andValues) { and_v[val] += 1; }
        int res = nums[0], ans = 0;
        for(int i = 0; ;++i) {
            while(i < n and not and_v.count(res)) {
                res = res & nums[i];
                i += 1;
            }
            if(i < n and and_v.count(res)) {
                and_v[res] -= 1;
                ans += nums[i];
                res = nums[i];
            } else {
                break;
            }
        }
        int const zc = std::count(and_v.begin(), and_v.end(), [&](std::pair<int const, int> const &a){ return a.second == 0; });

        return zc == and_v.size() ? ans : -1;
    }
};

int main() {
    std::vector<int> nums = {1,4,3,3,2}, andValues = {0,3,3,2};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minimumValueSum(nums, andValues));


    return 0;
}
