



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
public:
    static constexpr int const mod = 1'000'000'007;
public:
    inline static void solve() {
        int n = 0;
        std::cin >> n;
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        char c = '\0';
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> c;
                if (c != '*') {
                    if (i > 0) { dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod; }
                    if (j > 0) { dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod; }
                } else {
                    if (i == 0 && j == 0) {
                        std::cout << "0\n";
                        return;
                    }
                }
            }
        }

        std::cout << dp[n - 1][n - 1] << '\n';
    }
};

int main() { solution::solve(); }
