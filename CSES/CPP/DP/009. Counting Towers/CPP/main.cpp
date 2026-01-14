



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
public:
    inline static constexpr int const mod = 1'000'000'007;
public:
    std::vector<std::vector<int>> dp;
public:
    inline void solve(int const& n) {
        if (dp[n - 1][1] != 0) {
            int const res = (dp[n - 1][0] + 0LL + dp[n - 1][1]) % mod;
            std::cout << res << '\n';
            return;
        }
        dp[0][0] = 1; dp[0][1] = 1;

        for (int i = 1; i < n; ++i) {
            dp[i][1] = (      dp[i - 1][0] + 4LL * dp[i - 1][1]) % mod;
            dp[i][0] = (2LL * dp[i - 1][0] +       dp[i - 1][1]) % mod;
        }

        int const res = (dp[n - 1][0] + 0LL + dp[n - 1][1]) % mod;
        std::cout << res << '\n';
    }

    inline void solve() {
        int T = 0;
        std::cin >> T;
        dp.resize(1'000'001, std::vector<int>(2, 0));
        while (T--) {
            int n = 0;
            std::cin >> n;
            solve(n);
        }
    }
};

int main() { solution sol; sol.solve(); }
