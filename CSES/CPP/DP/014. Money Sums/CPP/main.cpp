



#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
public:
    inline static constexpr int const inf = 1 << 30;
public:
    inline static void solve(std::vector<int> const& coins, int const& target) {
        int const n = coins.size();
        std::vector<int> dp(target + 1, inf);
        dp[0] = 0;
        std::set<int> sums;
        for (int i = 0; i < n; ++i){
            for (int sub_target = target; sub_target > coins[i] - 1; --sub_target) {
                if (dp[sub_target] > dp[sub_target - coins[i]] + 1) {
                    int const prev = dp[sub_target];
                    dp[sub_target] = dp[sub_target - coins[i]] + 1;
                    if (prev == inf) {
                        sums.insert(sub_target);
                    }
                }
            }
        }
        std::cout << sums.size() << '\n';
        for (int const& sum: sums) { std::cout << sum << ' '; }
        std::cout << '\n';
    }

    inline static void solve() {
        int n = 0;
        std::cin >> n;
        std::vector<int> coins(n);
        int target = 0;

        for (int i = 0; i < n; ++i) { std::cin >> coins[i]; target += coins[i]; }
        std::sort(coins.begin(), coins.end());

        solve(std::vector<int>(coins.rbegin(), coins.rend()), target);
    }
};

int main() { solution::solve(); }
