



#include <vector>
#include <iostream>

struct solution {
public:
    inline static constexpr int const mod = 1'000'000'007;
public:
    inline static void count(std::vector<int> const& coins, int const& target) {
        int const n = coins.size();
        std::vector<int> dp(target + 1, target + 1);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int sub_target = coins[i]; sub_target < target + 1; ++sub_target) {
                dp[sub_target] = std::min(dp[sub_target], 1 + dp[sub_target - coins[i]]);
            }
        }

        std::cout << (dp[target] > target ? -1 : dp[target]) << '\n';
    }

    inline static void solve() {
        int n = 0, target = 0;
        std::cin >> n >> target;
        std::vector<int> coins(n);

        for (int i = 0; i < n; std::cin >> coins[i], ++i);
        count(coins, target);
    }
};

int main() { solution::solve(); }
