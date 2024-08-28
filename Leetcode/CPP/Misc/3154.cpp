



#include <bits/stdc++.h>

class Solution {
public:
    std::unordered_map<int, std::unordered_map<int, int>> g;
public:
    int nck(int n, int k) {
        if(g.count(n-1) and g[n-1].count(k-1) and g.count(n) and g[n].count(k-1)) {
            return g[n-1][k-1] + g[n-1][k];
        }
        int res = 1;
        for(int i =1; i <= k; ++i) {
            res = (res * 1LL * (n - i + 1)) / i;
            g[n][i] = res;
        }
        return g[n][k] = res;
    }
    
    int waysToReachStair(int k) {
        int ans = 0;
        for(int i = 0; i < 30; ++i) {
            int const r = (1 << i) - k;
            if(r >= 0 and r <= i + 1) {
                ans += nck(i+1, r); //dp[i+1][r];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.waysToReachStair(0));


    return 0;    
}
