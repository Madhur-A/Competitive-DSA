



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
public:
    inline static constexpr int const mod = 1'000'000'007;
public:
    inline static void solve(std::vector<int> const& nums, int m) {
        int const n = nums.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m + 1, 0));

        if (nums[0] == 0) {
            for (int j = 1; j < m + 1; ++j) { dp[0][j] = 1; }
        } else {
            dp[0][nums[0]] = 1;
        }

        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) { // then it can take all values between 1 and m (inclusive)
                for (int j = 1; j < m + 1; ++j) { // but these values are bounded by previous number
                    for (int k = std::max(1, j - 1); k < std::min(m + 1, j + 2); ++k) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    }
                }
            } else { // otherwise
                int const j = nums[i]; // bounded only by current value's bandwidth
                for (int k = std::max(1, j - 1); k < std::min(m + 1, j + 2); ++k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }

        int res = 0;

        for (int j = 1; j < m + 1; ++j) {
            res = (res + dp[n - 1][j]) % mod;
        }

        std::cout << res << '\n';
    }

    inline static void solve() {
        int n = 0, m = 0;
        std::cin >> n >> m;
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) { std::cin >> nums[i]; }

        solve(nums, m);
    }
};

int main() { solution::solve(); }
