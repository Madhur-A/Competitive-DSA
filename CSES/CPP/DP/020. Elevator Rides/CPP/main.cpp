



#include <vector>
#include <iostream>

struct solution {
    inline static void solve(std::vector<int> const& nums, int const& max_possible) {
        int const n = nums.size();
        std::vector<std::pair<int, long>> dp(1 << n, std::make_pair(n + 1, 0L)); // {rides, weight}
        dp[0] = std::make_pair(1, 0L);

        int next_mask = -1;
        std::pair<int, long> next_state;
        for (int i = 0; i < (1 << n); ++i) {
            int const rides = dp[i].first;
            long const total_weight = dp[i].second;
            for (int j = 0; j < n; ++j) {
                if (not (i & (1 << j))) {
                    next_mask = i | (1 << j);
                    if (total_weight + nums[j] <= max_possible) {
                        next_state = std::make_pair(rides, total_weight + nums[j]);
                    } else {
                        next_state = std::make_pair(rides + 1, nums[j]);
                    }
                    dp[next_mask] = std::min(next_state, dp[next_mask]);
                }
            }
        }

        std::cout << dp[(1 << n) - 1].first << '\n';
    }

    inline static void solve() {
        int n = 0, max_possible = 0;
        std::cin >> n >> max_possible;
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) { std::cin >> nums[i]; }

        solve(nums, max_possible);
    }
};

int main() { solution::solve(); }
