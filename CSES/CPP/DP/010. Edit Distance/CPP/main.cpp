



#include <vector>
#include <string>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
    inline static void solve(std::string const& s, std::string const& t) {
        int const r = s.length(), c = t.length();
        std::vector<std::vector<int>> dp(r + 1, std::vector<int>(c + 1, 0));

        for (int i = 1; i < r + 1; ++i) { dp[i][0] = i; }
        for (int j = 1; j < c + 1; ++j) { dp[0][j] = j; }

        for (int i = 1; i < r + 1; ++i) {
            for (int j = 1; j < c + 1; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }

        std::cout << dp[r][c] << '\n';
    }

    inline static void solve() {
        std::string s, t;
        std::cin >> s >> t;
        solve(s, t);
    }
};

int main() { solution::solve(); }
