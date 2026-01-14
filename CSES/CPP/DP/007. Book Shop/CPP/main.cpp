



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
    inline static void solve(std::vector<int> const& prices, std::vector<int> const& pages, int const& target) {
        int const n = prices.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));

        for (int i = 1; i < n + 1; ++i) {
            for (int price = 1; price < target + 1; ++price) {
                if (prices[i - 1] <= price) {
                    dp[i][price] = std::max(dp[i - 1][price], pages[i - 1] + dp[i - 1][price - prices[i - 1]]);
                } else {
                    dp[i][price] = dp[i - 1][price];
                }
            }
        }

        std::cout << dp[n][target] << '\n';
    }

    inline static void solve() {
        int n = 0, target = 0;
        std::cin >> n >> target;
        std::vector<int> prices(n), pages(n);
        for (int i = 0; i < n; ++i) { std::cin >> prices[i]; }
        for (int i = 0; i < n; ++i) { std::cin >> pages[i]; }

        solve(prices, pages, target);
    }
};

int main() { solution::solve(); }
