




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int dp[301][301];
    int px[301];    
public:    
    int custom_min(int const &a, int const &b) {        
        if(a == -1) { return b; }	
        if(b == -1) { return a; }
        return std::min(a, b);
    }
    
    int rx_min(int i, int j, int d, std::vector<int> const &nums) {
        if(j - i + 1  < d) { return 0; }
        if(dp[i][j] != -1) { return dp[i][j]; }
        for(int l = i; l < j; l += d-1) {
            dp[i][j] = custom_min(dp[i][j], rx_min(i, l, d, nums) + rx_min(l+1, j, d, nums));
        }
        if(not ((j-i) % (d-1))) { dp[i][j] += px[j+1] - px[i]; } // main core
        return dp[i][j];
    }
    
    int mergeStones(vector<int>& stones, int k) {
        int const n = stones.size();
        if(not ((n-1) % (k-1))) {
            memset(dp, -1, sizeof(dp));
            memset(px,  0, sizeof(px));
            std::partial_sum(stones.begin(), stones.end(), __builtin_addressof(px[1]));
            return rx_min(0, n-1, k, stones);
        }
        return -1;
    }
};
