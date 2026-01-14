



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
    inline static int solve(int const& a, int const& b) {
        std::vector<std::vector<int>> dp(a + 1, std::vector<int>(b + 1, 1 << 30));

        for (int i = 1; i < a + 1; ++i) {
            for (int j = 1; j < b + 1; ++j) {
                if (i == j) {
                    dp[i][j] = 0;
                } else {
                    for (int k = 1; k < i; ++k) {
                        dp[i][j] = std::min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]); // vertical cuts
                    }
                    for (int k = 1; k < j; ++k) {
                        dp[i][j] = std::min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]); // horizontal cuts
                    }
                }
            }
        }

        return dp[a][b];
    }

    inline static void solve() {
        int a = 0, b = 0;
        std::cin >> a >> b;
        int const res = (a == b) ? 0 : solve(a, b);

        std::cout << res << '\n';
    }
};

int main() { solution::solve(); }
