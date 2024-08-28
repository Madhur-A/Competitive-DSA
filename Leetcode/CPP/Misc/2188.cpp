



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
	int const n = numLaps + 1;
	std::vector<int> dp(n, INT_MAX);
	for(std::vector<int> const &tire: tires) {
	    int i = tire[0], j = tire[1], k = 1;
	    while(i < tire[0]+changeTime and k < n) {
		dp[k] = std::min(dp[k], j);
		i = i * tire[1];
		j = j + i;
		k = k + 1;
	    }
	}

	for(int i = 2; i < n; ++i) { // since the upper loop is determisitic about the optimality of time taken for the first lap
	    for(int j = 1; j * 2 < i+1; ++j) {
		dp[i] = std::min(dp[i], dp[j] + dp[i-j] + changeTime);
	    }
	}
	
	return dp[numLaps];
    }
};

int main() {

    return 0;
}
