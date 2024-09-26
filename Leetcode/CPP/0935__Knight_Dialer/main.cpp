



#include <bits/stdc++.h>

class Solution {
public:
    static constexpr int const mod = 1'000'000'007;
public:
    std::unordered_map<int, std::vector<int>> g;
    int dp[10][5001];
public:
    int rx(int const &number, int const &limit, int const &digits) {
        if(digits == limit - 1) { return 1; }
        int res = 0;
        if(dp[number][digits]) { return dp[number][digits]; }
        for(int const &child: g[number]) {
            res += rx(child, limit, digits + 1);
            res %= mod;
        }

        return dp[number][digits] = res;
    }

    int knightDialer(int n) {
        g[0] = {4, 6}; g[1] = {6, 8}; g[2] = {7, 9}; g[3] = {4, 8};
        g[4] = {0, 3, 9}; g[6] = {0, 1, 7};
        g[7] = {2, 6}; g[8] = {1, 3}; g[9] = {2, 4};
        memset(dp, 0, sizeof(dp));
        long res = 0L;
        for(int i = 0; i < 10; ++i) {
            res += rx(i, n, 0);
            res %= mod;
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.knightDialer(1));


    return 0;
}
