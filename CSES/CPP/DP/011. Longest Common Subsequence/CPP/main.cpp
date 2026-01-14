



#include <vector>
#include <cstring>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
    inline static void solve(std::vector<int> const& a, std::vector<int> const& b) {
        int const r = a.size(), c = b.size();
        std::vector<std::vector<int>> dp(r + 1, std::vector<int>(c + 1, 0));

        for (int i = 1; i < r + 1; ++i) {
            for (int j = 1; j < c + 1; ++j) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        std::vector<int> path;

        int i = r, j = c;
        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                path.push_back(a[i - 1]);
                --i; --j;
            } else if (dp[i][j - 1] <= dp[i - 1][j]) {
                --i;
            } else {
                --j;
            }
        }

        std::cout << dp[r][c] << '\n';
        std::vector<int>::const_reverse_iterator s = path.rbegin();
        while (s != path.rend()) { std::cout << *s << ' '; ++s; }
        std::cout << '\n';
    }

    inline static void solve() {
        int n = 0, m = 0;
        std::cin >> n >> m;
        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) { std::cin >> a[i]; }
        for (int i = 0; i < m; ++i) { std::cin >> b[i]; }

        solve(a, b);
    }
};

int main() { solution::solve(); }
