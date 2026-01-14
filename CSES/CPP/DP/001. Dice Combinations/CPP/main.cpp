



#include <vector>
#include <iostream>

struct solution {
public:
    inline static constexpr int const mod = 1'000'000'007;
public:
    inline static void solve() {
        int target = 0;
        std::cin >> target;
        std::vector<int> dp(target + 1, 0);

        dp[0] = 1;
        for (int sub_target = 0; sub_target < target + 1; ++sub_target) {
            for (int const& face: {1,2,3,4,5,6}) {
                if (face <= sub_target) {
                    dp[sub_target] = (dp[sub_target] + 0L + dp[sub_target - face]) % mod;
                }
            }
        }

        std::cout << dp[target] << '\n';
    }
};

int main() { solution::solve(); }
