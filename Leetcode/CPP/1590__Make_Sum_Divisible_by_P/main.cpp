



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> seen;
public:
    int minSubarray(vector<int>& nums, int p) {
        int const n = nums.size(), rem = std::accumulate(nums.begin(), nums.end(), 0L) % p;
        if(rem != 0) {
            seen[0] = -1;
            int curr = 0, ans = INT_MAX;
            for(int i = 0; i < n; ++i) {
                curr += nums[i];
                curr %= p;
                if(seen.count((curr - rem + p) % p)) {
                    ans = std::min(ans, i - seen[(curr - rem + p) % p]);
                }
                seen[curr] = i;
            }
            return (ans == INT_MAX or ans == n) ? -1 : ans;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1,2,3};
    int const p = 3;
    std::fprintf(stdout, "%d\n", sol.minSubarray(nums, p));


    return 0;
}
