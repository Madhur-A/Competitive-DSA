




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int dp[1001][101][2];
public:
    int dfs(int index, int txn, int bought, int k, vector<int>& prices) {
        int const n = prices.size();
        if(index < n) {
            if(dp[index][txn][bought] != -1) { return dp[index][txn][bought]; }
            if(bought and txn < k) {
                dp[index][txn][bought] = std::max(dfs(index+1, txn, bought, k, prices),
                                                  dfs(index+1, txn+1, 0, k, prices) + prices[index]);
            } else {
                dp[index][txn][bought] = std::max(dfs(index+1, txn, bought, k, prices),
                                                  dfs(index+1, txn, 1, k, prices) - prices[index]);
            }
            return dp[index][txn][bought];
        }
        return 0;
    }

    int maxProfit(int k, vector<int>& prices) {
        int const n = prices.size();
//        memset(dp, -1, sizeof(dp)); // for top-down above
//        return dfs(0, 0, 0, k, prices);
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i < k+1; dp[0][i][1] = -prices[0], ++i);

        for(int i = 1; i < n; ++i) {
            for(int txn = k; txn > 0; --txn) {
                dp[i][txn][0] = std::max(dp[i-1][txn][0], dp[i-1][txn][1] + prices[i]);
                dp[i][txn][1] = std::max(dp[i-1][txn][1], dp[i-1][txn-1][0] - prices[i]);
            }
        }

        return dp[n-1][k][0];
    }
};

int main() {
    Solution sol;
    int k = 2;
    std::vector<int> prices = {2,4,1};
    std::fprintf(stdout, "%d\n", sol.maxProfit(k, prices));

    return 0;
}

