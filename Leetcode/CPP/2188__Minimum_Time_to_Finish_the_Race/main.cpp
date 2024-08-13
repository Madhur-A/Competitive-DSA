



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    long costs[18];
    long mosts[1001];
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        memset(costs, 0x7F, sizeof(costs));
        memset(mosts, 0x7F, sizeof(mosts));

        for(std::vector<int> const &tire: tires) {
            int const f = tire[0], r = tire[1];
            long laps = 1, curr = 0, next = f;
            while(next <= changeTime + f) {
                curr += next;
                costs[laps] = std::min(costs[laps], curr);
                next = next * r;
                laps = laps + 1;
            }
        }

        mosts[0] = -changeTime;

        for(int i = 1; i < numLaps+1; ++i) {
            for(int j = 1; j < std::min(18, i+1); ++j) {
                mosts[i] = std::min(mosts[i], mosts[i-j] + costs[j]);
            }
            mosts[i] += changeTime;
        }

        return mosts[numLaps];
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tires = {{2,3},{3,4}};
    int changeTime = 5, numLaps = 4;
    std::fprintf(stdout, "%d\n", sol.minimumFinishTime(tires, changeTime, numLaps));


    return 0;
}
