




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
public:
    //1. Using PQ
    int bfs_prioritized(std::vector<int> const &coins, int target) {
        using element = std::pair<int, long>; // count, sum
        std::priority_queue<element, std::vector<element>, std::greater<element>> t;
        std::unordered_set<long> seen;
        t.push({0, 0L});
        while(not t.empty()) {
            element const p = t.top(); t.pop();
            if(p.second == target) { return p.first; }
            for(int const &coin: coins) {
                if(p.second + coin <= target and not seen.count(p.second + coin)) {
                    t.push({p.first + 1, p.second + coin});
                    seen.insert(p.second + coin);
                }
            }
        }

        return -1;
    }

    //2. Using Vanilla BFS
    int bfs_vanilla(std::vector<int> const &coins, int target) {
        std::queue<long> t;
        std::unordered_map<long, int> seen;
        t.push(0L);
        seen[0L] = 0;
        while(not t.empty()) {
            int const p = t.front(); t.pop();
            if(p == target) { return seen[p]; }
            for(int const &coin: coins) {
                if(p + 0L + coin <= target and not seen.count(p + coin)) {
                    t.push(p + coin);
                    seen[p + coin] = seen[p] + 1;
                }
            }
        }

        return -1;
    }

    //3. DP top-down
    int dfs(std::vector<int> &coins, int target) {
        int const inf = INT_MAX / 2;
        std::unordered_map<int, int> dp;
        std::ranges::reverse(coins);
        std::function<int(int)> rx = [&](int remaining) {
            if(remaining      == 0) { return 0;             }
            if(dp.count(remaining)) { return dp[remaining]; }

            int res = inf, aux = -1;
            for(int const &coin: coins) {
                if(remaining >= coin and coin != 0) {
                    aux = rx(remaining - coin);
                    if(aux != -1) {
                        res = std::min(res, 1 + aux);
                    }
                }
            }
            return dp[remaining] = (inf <= res) ? -1 : res;
        };

        return rx(target);
    }

    //4. DP bottom-up aka the traditional coin-change problem
    int bottom_up(std::vector<int> const &coins, int target) {
        std::vector<int> dp(target + 1, target + 1);
        dp[0] = 0;
        for(int const &coin: coins) {
            for(int j = coin; j < target+1; ++j) {
                dp[j] = std::min(dp[j], dp[j - coin] + 1);
            }
        }

        return (dp[target] > target) ? -1 : dp[target];
    }

    int coinChange(vector<int>& coins, int target) {
//         return bfs_prioritized(coins, target);
//         return bfs_vanilla(coins, target);
//         return dfs(coins, target);
         return bottom_up(coins, target);
    }
};

 int main() {
     Solution sol;
     std::vector<int> coins = {1,2,5};
     int target = 11;
     std::fprintf(stdout, "%d\n", sol.coinChange(coins, target));

     return 0;
 }
