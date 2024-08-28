



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int const n = nums.size();
        std::vector<int> evn_n, odd_n, evn_t, odd_t;
        for(int i = 0; i < n; ++i) {
            int const num = nums[i], dst = target[i];
            (num & 1) ? odd_n.push_back(num) : evn_n.push_back(num);
            (dst & 1) ? odd_t.push_back(dst) : evn_t.push_back(dst);
        }
        std::ranges::sort(odd_n); std::ranges::sort(evn_n);
        std::ranges::sort(odd_t); std::ranges::sort(evn_t);
        long res = 0;
        for(unsigned long i = 0; i < odd_n.size(); ++i) { res += std::abs(odd_n[i] - odd_t[i]); }
        for(unsigned long i = 0; i < evn_n.size(); ++i) { res += std::abs(evn_n[i] - evn_t[i]); }
        
        
        return res/4;
    }
};

int main() {
    std::vector<int> nums = {8,12,6}, target = {2,14,10};
    Solution sol;
    std::fprintf(stdout, "%lld\n", sol.makeSimilar(nums, target));


    return 0;
}
