



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::vector<std::vector<int>> dp;
public:
    int rx(std::vector<std::vector<int>> const &events, int const &count, int const &index) {
        // this is giving TLE
        int const n = events.size();
        if(count == 0 or index == n) { return 0; }
        if(dp[index][count]   != -1) { return dp[index][count]; }
        int left = 0, right = n, mid = 0;
        while(left < right) {
            mid = left + ((right - left) >> 1);
            if(events[mid][0] > events[index][1]) {
                right = mid;
            } else {
                left  = mid + 1;
            }
        }
        return dp[index][count] =
            std::max(rx(events, count, index+1), events[index][2] + rx(events, count-1, left));
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int const n = events.size();
        std::ranges::sort(events, [](std::vector<int> const &a, std::vector<int> const &b){
            return a[0] < b[0];
        });
        // dp.resize(n+1, std::vector<int>(k+1, -1));
        dp.resize(k+1, std::vector<int>(n+1));
        for(int index = n-1; index >= 0; --index) {
            for(int count = 1; count <= k; ++count) {
                int left = 0, right = n, mid = 0;
                while(left < right) {
                    mid = left + ((right - left) >> 1);
                    if(events[mid][0] > events[index][1]) {
                        right = mid;
                    } else {
                        left  = mid + 1;
                    }
                }
                dp[count][index] =
                    std::max(dp[count][index+1], events[index][2] + dp[count-1][left]);
            }
        }
        // return rx(events, k, 0);
        return dp[k][0];
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> events = {{1,2,4},{3,4,3},{2,3,1}};
    int k = 2;    
    std::fprintf(stdout, "%d\n", sol.maxValue(events, k));


    return 0;
}
