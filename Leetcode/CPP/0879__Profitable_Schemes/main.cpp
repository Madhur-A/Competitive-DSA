



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    inline static constexpr int const mod = 1000000007;
public:
    int dp[101][101][101];
public:
    int dfs(vector<int>& group, vector<int>& profit, int people, int money, int index) {
        if(index >= (int)group.size()) { return (money == 0); }

        if(dp[index][people][money] != -1) { return dp[index][people][money]; }

        long res = dfs(group, profit, people, money, index + 1);
        res = res + ((people >= group[index]) ?
                        dfs(group, profit, people-group[index], std::max(0, money-profit[index]), index + 1) :
                        0);
        return dp[index][people][money] = res % mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return dfs(group, profit, n, minProfit, 0); //top-down, below is the bottom-up

//         memset(dp,  0, sizeof(dp)); // only 2D dp is needed here viz., dp[101][101]
//         for(int i = 0; i < n+1; dp[i][0] = 1, ++i);

//         for(int i = 1; i < sz+1; ++i) {
//             int const people = group[i-1], money = profit[i-1];
//             for(int j = n; j >= people; --j) {
//                 for(int k = minProfit; k >= 0; --k) {
//                     dp[j][k] += dp[j-people][std::max(0, k-money)];
//                     dp[j][k] %= mod;
//                 }
//             }
//         }

//         return dp[n][minProfit];
    }
};

int main() {
    Solution sol;
    int n = 5, minProfit = 3;
    std::vector<int> group = {2,2}, profit = {2,3};    
    std::fprintf(stdout, "%d\n", sol.profitableSchemes(n, minProfit, group, profit));




    return 0;
}
