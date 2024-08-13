



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::map<int, int> g;
    std::unordered_set<int> divs;
public:
    int minOperations(vector<int>& nums, vector<int>& nums_divide) {
        for(int const &num: nums) { g[num] += 1; }
        divs.insert(nums_divide.begin(), nums_divide.end());

        int ans = 0, total_freq = 0;

        for(std::pair<int const, int> const &node: g) {
            int const num = node.first, freq = node.second;
            total_freq += freq;
            bool flag = true;
            for(int const &d: divs) {
                if((d % num) != 0) {
                    ans += freq;
                    flag = false;
                    break;
                }
            }
            if(flag) { return ans; }
        }

        return (ans == total_freq) ? -1 : ans;
    }
};

int main() {    
    Solution sol;
    std::vector<int> nums = {2,3,2,4,3}, nums_divide = {9,6,9,3,15};    
    std::fprintf(stdout, "%d\n", sol.minOperations(nums, nums_divide));

    return 0;
}

