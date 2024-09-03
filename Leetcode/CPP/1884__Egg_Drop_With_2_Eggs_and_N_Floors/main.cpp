



#include <bits/stdc++.h>

class Solution {
public:
    int dp[1001][3];
    int dq[1001][3];
public:
    int rx(int floors, int eggs) { // DP; top-down
        if(floors <= 1 or eggs ==  1) { return floors; } // per problem constraints
        if(dp[floors][eggs]    != -1) { return dp[floors][eggs]; }

        int res = INT_MAX;

        for(int reached = 1; reached <= floors; ++reached) {
            res = std::min(res, 1 + std::max(rx(reached - 1, eggs - 1), rx(floors - reached, eggs)));
        }

        return dp[floors][eggs] = res;
    }

    int bx(int floors, int eggs) { // same as before; but with binary-search (find-left or std::lower_bound)
        if(floors <= 1 or eggs == 1) { return floors; }
        if(dp[floors][eggs]   != -1) { return dp[floors][eggs]; }

        int left = 0, right = floors, mid = 0, res = 0;

        while(left < right) {
            mid = left + ((right - left) >> 1);
            res = 1 + std::max(bx(mid - 1, eggs - 1), bx(floors - mid, eggs));
            if(res > mid) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }

        return dp[floors][eggs] = left;
    }

    int dx(int floors, int eggs) { // DP; bottom-up sans optimizationxs
        for(int i = 0; i < floors + 1; ++i) { dp[i][0] = i; dp[i][1] = i; }
        for(int j = 0; j < eggs + 1;   ++j) { dq[0][j] = 0; }

        for(int k = 1; k < eggs + 1; ++k) {
            for(int n = 0; n < floors + 1; ++n) {
                for(int next = 0; next < n + 1; ++next) {
                    dq[n][k] = std::min(dq[n][k], 1 + std::max(dq[n - next][k - 1], dq[next - 1][k]));
                }
            }
        }
        return  dq[floors][eggs];
    }

    int twoEggDrop(int n) {
//        return std::floor(std::sqrt(2.0 * n) + 0.5); // seq: for i <- [1, n] { {i, i, ... -i times- } }

        memset(dp, 0xFF, sizeof(dp));
        memset(dq, 0x7F, sizeof(dq));


//        return rx(n, 2);
//        return dx(n, 2);
        return bx(n, 2);
    }
};


int main() {
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.twoEggDrop(100));


    return 0;
}
