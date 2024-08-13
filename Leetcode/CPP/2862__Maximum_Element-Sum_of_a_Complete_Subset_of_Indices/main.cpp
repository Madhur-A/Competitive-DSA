



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, long> seen;
public:
    long long maximumSum(vector<int>& nums) {
        int const n = nums.size();
        long ans = 0L;
        for(int i = 0; i < n; ++i) {
            int num = i + 1, k = 2;
            while(k*k <= num) {
                while((num % (k*k)) == 0) { num = num / (k*k); }
                k += 1;
            }
            seen[num] += nums[i];
            ans = std::max(ans, seen[num]);
        }
        return ans;
    }
};

int main() {    
    std::vector<int> nums = {8,7,3,5,7,2,4,9};
    Solution sol;
    std::fprintf(stdout, "%lld\n", sol.maximumSum(nums));


    return 0;
}

