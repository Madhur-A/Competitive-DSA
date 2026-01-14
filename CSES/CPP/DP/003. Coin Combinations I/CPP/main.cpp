



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
public:
    static constexpr int const mod = 1'000'000'007;
public:
    inline static void count(std::vector<int> const& coins, int const& target) {
        int const n = coins.size();
        std::vector<int> dp(target + 1);
        dp[0] = 1;

        for (int sub_target = 1; sub_target < target + 1; ++sub_target) {
            for (int i = 0; i < n; ++i) {
                if (coins[i] <= sub_target) {
                    dp[sub_target] += dp[sub_target - coins[i]];
                    dp[sub_target] %= mod;
                }
            }
        }

        std::cout << dp[target] << '\n';
    }

    inline static void solve() {
        int n = 0, target = 0;
        std::cin >> n >> target;
        std::vector<int> coins(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> coins[i];
        }
        count(coins, target);
    }
};

int main() { solution::solve(); }
