



#include <vector>
#include <iostream>
#include <string>

struct solution {
public:
    using _1d = std::vector<long>;
    using _2d = std::vector<_1d>;
    using _3d = std::vector<_2d>;
    using _4d = std::vector<_3d>;
public:
    inline static long solve(long const& num) {
        int const n = std::to_string(num).length();
        std::string const s = std::to_string(num);

        // dp[i][prev][equal][empty] :: number of valid numbers from index i

        // prev  :: last digit used (0 to 9)
        // equal :: whether the current number is still equal to the prefix of num [0/1]
        // empty :: whether or not a non-zero digit has been placed [0/1]

        _4d dp(n + 1, _3d(10, _2d(2, _1d(2, 0L))));

        // initial case
        dp[0][0][1][1] = 1;

        for (int i = 0; i < n; ++i) {
            int const digit = s[i] - '0';
            for (int prev = 0; prev < 10; ++prev) {
                for (int equal = 0; equal < 2; ++equal) {
                    for (int empty = 0; empty < 2; ++empty) {
                        if (dp[i][prev][equal][empty] == 0) { continue; }

                        int const limit = equal ? digit : 9;  // if equal then next choice is constrained by s[i]

                        for (int d = 0; d < limit + 1; ++d) {
                            if (not empty and d == prev) { continue; }  // skip
                            dp[i + 1][d][equal and d == digit][empty and d == 0] += dp[i][prev][equal][empty]; // pick
                        }
                    }
                }
            }
        }


        long res = 0L; // sum of all states at the last position
        for (int prev = 0; prev < 10; ++prev) {
            for (int equal = 0; equal < 2; ++equal) {
                for (int empty = 0; empty < 2; ++empty) {
                    res += dp[n][prev][equal][empty];
                }
            }
        }

        return res;
    }

    inline static void solve() {
        long a = 0, b = 0;
        std::cin >> a >> b;
        std::cout << solve(b) - solve(a - 1) << '\n';
    }
};

int main() { solution::solve(); }
