



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int dp[1001];
    int seen[1001][1001];
public:
    int rx(std::vector<int> const &nums, int k, int index) {
        int const n = nums.size();
        if(index     >=  n) { return 0;         }
        if(dp[index] != -1) { return dp[index]; }
        int cost = INT_MAX, unique = 0;
        for(int i = index; i < n; ++i) {
            int const num = nums[i];
            seen[index][num] += 1;
            unique += (seen[index][num] == 1);
            unique -= (seen[index][num] == 2);
            cost = std::min(cost, k + i - index + 1 - unique + rx(nums, k, i+1));
        }
        return dp[index] = cost;
    }
    
    int minCost(vector<int>& nums, int k) {
        memset(dp,  -1, sizeof(dp));
        memset(seen, 0, sizeof(seen));
        return rx(nums, k, 0);
    }
};

int main() {
    std::vector<int> nums = {5,6,4,3,2,5,4,1,5,2,0,5,4,3,1,5,4,3,4,4};
    int k = 3;
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minCost(nums, k));


    return 0;
}
