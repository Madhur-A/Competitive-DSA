



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_set<int> seen;
    std::unordered_map<int, bool> memo;
public:
    bool circularArrayLoop(vector<int>& nums) {
        int const n = nums.size();

        std::function<bool(int, int)> find =  [&](int source, int sign) {
            if(memo.count(source))      { return memo[source]; }
            if(seen.count(source))      { return true;  }
            if(nums[source] * sign < 0) { return false; }
            seen.insert(source);
            int next = (nums[source] + source) % n;
            next = next + n * (next < 0);
            if(next == source) { //self-loop
                return false;
            }

            return memo[source] = find(next, sign);
        };

        for(int i = 0; i < n; ++i) {
            seen.clear();
            int sign = nums[i] >= 0 ? 1 : -1;
            if(find(i, sign)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    std::vector<int> nums = {-1,-2,-3,-4,-5,6};
    Solution sol;
    std::cout.setf(std::ios::boolalpha);
    std::cout << sol.circularArrayLoop(nums) << '\n';
}
