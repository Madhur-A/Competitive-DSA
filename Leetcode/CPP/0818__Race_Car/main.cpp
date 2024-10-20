



#include <bits/stdc++.h>

class Solution {
public:
    int racecar(int target) {
		int dp[target + 1];
		memset(dp, 0, sizeof(dp));

		for(int i = 1; i <=  target; ++i) {
			int nearest = 32 - __builtin_clz(i);
			if(i == (1 << nearest) - 1) { //perfect match found
				dp[i] = nearest;
			} else {
				dp[i] = dp[(1 << nearest) - 1 -  i] + nearest + 1;
				for(int j = 0; j < nearest; ++j) {
					int const remains = (1 << (nearest - 1)) - (1 << j);
					dp[i] = std::min(dp[i], dp[i - remains] + nearest - 1 + j + 2);
				}
			}
		}

		return dp[target];
    }
};

int main() {
	Solution sol;
	std::fprintf(stdout, "%d\n", sol.racecar(3));

	return 0;
}
