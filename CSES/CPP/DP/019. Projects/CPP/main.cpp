



#include <vector>
#include <array>
#include <iostream>
#include <algorithm>

struct solution {
    inline static void solve(std::vector<std::array<int, 3>> const& nums) {
        int const n = nums.size();
        std::vector<long> dp(n + 1);

        for (int i = 0; i < n; ++i) {
            int left = 0, right = i - 1, mid = 0; // inclusive of bounds
            while (left <= right) {
                mid = left + ((right - left + 1) >> 1);
                if (nums[mid][1] < nums[i][0]) {
                    left  = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            dp[i + 1] = std::max(dp[i], dp[right + 1] + nums[i][2]);
        }

        std::cout << dp[n] << '\n';
    }

    inline static void solve() {
        int n = 0;
        std::cin >> n;
        std::vector<std::array<int, 3>> nums(n);
        for (int i = 0; i < n; ++i) { std::cin >> nums[i][0] >> nums[i][1] >> nums[i][2]; }
        std::sort(nums.begin(), nums.end(), [](std::array<int, 3> const& a,
                                               std::array<int, 3> const& b) { return a[1] < b[1]; });


        solve(nums);
    }
};

int main() { solution::solve(); }
