



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    inline static constexpr long const inf = LONG_MIN / 2;
public:
    std::vector<std::vector<long>> dp;
public:
    // top down
    long rx(std::vector<int> const &a, std::vector<int> const &b, int count, int index) {
        int const n = b.size();
        if(count == 4) { return 0;   }
        if(n <= index) { return inf; }
        if(count >  4) { return inf; }

        if(dp[count][index] != inf) { return dp[count][index]; }

        long const skip = rx(a, b, count, index + 1);
        long const pick = rx(a, b, count + 1, index + 1) + a[count] * 1L * b[index];

        return dp[count][index] = std::max(pick, skip);
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        int const n = b.size();
        dp.resize(5, std::vector<long>(n + 1, inf));

        // return rx(a, b, 0, 0); // top -down

        /*** Bottom Up ***/
        for(int i = 0; i < n + 1; ++i) { dp[0][i] = 0; }
        for(int j = 0; j < 5; ++j) { dp[j][j] = 0;}

        for(int i = 1; i < 5; ++i) {
            for(int j = 1; j < n + 1; ++j) {
                dp[i][j] = std::max(dp[i][j - 1], a[i - 1] * 1L * b[j - 1] + dp[i - 1][j - 1]);
            }
        }

        return dp.back().back();
    }
};

int main() {
    Solution sol;
    std::vector<int> a =  {3,2,5,6}, b = {2,-6,4,-5,-3,2,-7};



    return std::fprintf(stdout, "%lld\n", sol.maxScore(a, b));
}
