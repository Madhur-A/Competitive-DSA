



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    inline static constexpr int const mod = 1'000'000'007;
public:
    int dp[1001][1001];
public:
    int stirling(int n, int k) {
        if(k == 0) { return n == 0; }
        if(n == k) { return 1; }
        if(dp[n][k]) { return dp[n][k]; }
        return dp[n][k] = (stirling(n-1, k-1) + 0LL + (n-1) * 1LL * stirling(n-1, k)) % mod;
    }

    int rearrangeSticks(int n, int k) {
        memset(dp, 0, sizeof(dp));
        return stirling(n, k);
    }
};

int main() {
    Solution sol;
    int const n = 20, k = 11;    
    std::fprintf(stdout, "%d\n", sol.rearrangeSticks(n, k));

    return 0;
}
