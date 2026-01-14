



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
    inline static void solve(std::vector<int> const& nums) {
        int const n = nums.size();
        std::vector<std::vector<long>> dp(n, std::vector<long>(n, 0));
        dp[0][0] = nums[0];
        for (int i = 0; i < n - 1; ++i) {
            dp[i + 1][i + 1] = nums[i + 1];
            dp[i][i + 1] = std::max(nums[i], nums[i + 1]);
        }

        for (int len = 3; len < n + 1; ++len) {
            for (int left = 0; left < n - len + 1; ++left) {
                int right = left + len - 1;
                dp[left][right] = std::max(
                                           nums[left] + std::min(left + 1 < right ? dp[left + 2][right] : 0, dp[left + 1][right - 1]),
                                           nums[right] + std::min(left < right - 1 ? dp[left][right - 2] : 0, dp[left + 1][right - 1])
                                           );

            }
        }


        std::cout << dp[0][n - 1] << '\n';
    }

    inline static void solve() {
        int n = 0;
        std::cin >> n;
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) { std::cin >> nums[i]; }

        solve(nums);
    }
};

int main() { solution::solve(); }
