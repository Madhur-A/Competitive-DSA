



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    long long dp[1001][1001];
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int const n = dist.size();
        memset(dp, 0LL, sizeof(dp));
        dp[0][0] = dist[0];
        for(int i = 1; i < n; ++i) {
            long long num = dp[i - 1][0] + (speed - dp[i - 1][0] % speed) % speed;
            dp[i][0] = num + dist[i];
            for(int j = 1; j < i; ++j) {
                num = dp[i - 1][j] + (speed - dp[i - 1][j] % speed) % speed;
                dp[i][j] = std::min(num, dp[i - 1][j - 1]) + dist[i];
            }
            dp[i][i] = dp[i - 1][i - 1] + dist[i];
        }

        for(int j = 0; j < n; ++j) {
            if(dp[n - 1][j] <= hoursBefore * 1LL * speed) {
                return j;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> dist = {7,3,5,5};
    int speed = 2, hoursBefore = 10;
    std::fprintf(stdout, "%d\n", sol.minSkips(dist, speed, hoursBefore));



    return 0;
}
