



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    inline static constexpr int const inf = 1'000'000'007;
public:
    int dp[101][101][21];
public:
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int target, int colors, int prev, int index) {
        int const n = houses.size();
        if(target < 0) { return inf; }
        if(index == n) { return target == 0 ? target : inf; }
        if(dp[index][target][prev]) { return dp[index][target][prev]; }

        if(houses[index] != 0) {
            return dfs(houses, cost, target - (prev != houses[index]), colors, houses[index], index+ 1);
        }
        int res = inf;
        for(int color = 1; color <= colors; ++color) {
            res = std::min(
                cost[index][color-1] + dfs(houses, cost, target - (prev != color), colors, color, index+1),
                res
            );
        }
        return dp[index][target][prev] = res;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, 0, sizeof(dp));
        int const ans = dfs(houses, cost, target, n, 0, 0);
        return ans == inf ? -1 : ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> houses = {0,0,0,0,0};
    std::vector<std::vector<int>> cost = {{1,10},{10,1},{10,1},{1,10},{5,1}};
    int m = 5, n = 2, target = 3;    
    std::fprintf(stdout, "%d\n", sol.minCost(houses, cost, m, n, target));


    return 0;
}
