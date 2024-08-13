



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long ans = 0;
        std::stack<std::pair<int, int>> t;
        for(int const &num: nums) {
            while(not t.empty() and t.top().first < num) { t.pop(); }
            if(t.empty() or t.top().first != num) { t.push({num, 0}); }
            t.top().second += 1;
            ans += t.top().second;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1,4,3,3,2};
    std::fprintf(stdout, "%lld\n", sol.numberOfSubarrays(nums));



    return 0;
}
