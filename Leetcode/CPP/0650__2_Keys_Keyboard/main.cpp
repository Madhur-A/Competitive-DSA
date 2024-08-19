




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int dp[1001];
public:
    int top_down(int n) {
        if(n <= 1) { return 0; }
        if(dp[n]) { return dp[n]; }
        int res = n;
        for(int i = 2; i < n; ++i) {
            if(n % i == 0) {
                res = std::min(res, n / i + top_down(i));
            }
        }

        return dp[n] = res;
    }

    int bottom_up(int n) {
        for(int i = 2; i < n+1; ++i) {
            dp[i] = i;
            for(int j = 1; j <= i/2; ++j) {
                if((i % j) == 0) {
                    dp[i] = std::min(dp[i], dp[j] + i / j);
                }
            }
        }

        return dp[n];
    }

    int minSteps(int n) {
        memset(dp, 0, sizeof(dp));

        return top_down(n);
        // return bottom_up(n);
    }
};

int main() {
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minSteps(3));

    return 0;
}

