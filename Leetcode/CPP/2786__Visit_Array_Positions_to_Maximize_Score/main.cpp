



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
	std::vector<std::vector<long>> dp;
public:
    long long maxScore(vector<int>& nums, int x) {
		int const n = nums.size();
		dp.resize(n, std::vector<long>(2, INT_MIN));

		dp[0][nums[0] & 1] = nums[0];

		for(int i = 1; i < n; ++i) {
			int const curr = nums[i] & 1;
			int const prev = curr ^ 1;
			dp[i][curr] = std::max(dp[i - 1][curr] + nums[i], dp[i - 1][prev] + nums[i] - x);
			dp[i][prev] = std::max(dp[i - 1][prev], dp[i - 1][curr] + nums[i] - x);
		}

		return std::ranges::max(dp[n - 1]);
    }
};

int main() {
	Solution sol;
	std::vector<int> nums = {2,3,6,1,9,2};
	int x = 5;
	std::fprintf(stdout, "%lld\n", sol.maxScore(nums, x));


	return 0;
}


// [8,50,65,85,8,73,55,50,29,95,5,68,52,79]
// 74
// expected 470
