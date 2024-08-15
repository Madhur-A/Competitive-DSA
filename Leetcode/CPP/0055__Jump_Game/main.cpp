



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int const n = nums.size();
        int possible = 0;
        for(int i = 0; i < n; ++i) {
            if(possible  <   i) { return false; }            
            possible = std::max(possible, i + nums[i]);
            if(possible >= n-1) { return true;  }
        }
        return true;
    }
};


int main() {
    Solution sol;
    std::vector<int> nums = {2,3,1,1,4};
    std::cout.setf(std::ios::boolalpha);
    std::cout << sol.canJump(nums) << '\n';
    
    return 0;
}
