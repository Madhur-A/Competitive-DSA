



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
public:
    inline static constexpr int const mod = 1'000'000'007;
public:
    inline static void solve(int const& n) {
        int const total = (n * (n + 1)) >> 1;
        if (total & 1) { std::cout << "0\n"; return; }
        int const target = total >> 1;

        std::vector<long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < n + 1; ++i) {
            for (int sub_target = target; sub_target > i - 1; --sub_target) {
                dp[sub_target] = (dp[sub_target] + dp[sub_target - i]) % mod;
            }
        }

        std::cout << (dp[target] * 500000004LL) % mod << '\n';
    }

    inline static void solve() {
        int n = 0;
        std::cin >> n;

        solve(n);
    }
};

int main() { solution::solve(); }
