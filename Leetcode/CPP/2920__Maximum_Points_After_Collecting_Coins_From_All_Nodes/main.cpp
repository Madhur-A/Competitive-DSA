



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::vector<std::vector<int>> g;
    std::vector<std::vector<int>> dp;
public:
    int dfs(int node, int parent, int sbit, int m, int k, vector<int>& coins) {
        if(sbit           >=  m) { return 0; }
        if(dp[node][sbit] != -1) { return dp[node][sbit]; }
        int const value = coins[node]/(1 << sbit);
        int res_a = value - k, res_b = std::floor(value/2.0);
        for(int const &child: g[node]) {
            if(child != parent) {
                res_a += dfs(child, node, sbit,   m, k, coins);
                res_b += dfs(child, node, sbit+1, m, k, coins);
            }
        }

        return dp[node][sbit] = std::max(res_a, res_b);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int const n = coins.size(), m = 14; // as max possible value for coins is 10,000 ~ 2^14
        g.resize(n);
        dp.resize(n, std::vector<int>(m, -1));
        for(std::vector<int> const &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        return dfs(0, -1, 0, m, k, coins);
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,3}};
    std::vector<int> coins = {10,10,3,3};
    int k = 5;
    std::fprintf(stdout, "%d\n", sol.maximumPoints(edges, coins, k));


    return 0;
}
