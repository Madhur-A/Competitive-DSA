



class Solution {
public:
	int dp[366][3];
    int permit[3] = {1, 7, 30};
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
		int const n = days.size();
		memset(dp, 0x7F, sizeof(dp));
		dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;

		std::function<int(int const&)> find_index = [&](int const &target) {
			return std::lower_bound(days.begin(), days.end(), target) - days.begin();
		};

		// this is bottom-up
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < 3; ++j) {
				for(int k = 0; k < 3; ++k) {
					int const next_index = find_index(days[i] + permit[k]);
					dp[next_index][j] = std::min(dp[next_index][j], costs[k] + dp[i][j]);
				}
			}
		}

		return dp[n][0];

		// this is top-down

		// memset(dp, 0xFF, sizeof(dp)); // reset the dp
		// std::function<int(int const&, int const&)> rx = [&](int const &index, int const &permit_type) {
		// 	if(index < n) {
		// 		if(dp[index][permit_type] != -1) { return dp[index][permit_type]; }
		// 		return dp[index][permit_type] = std::ranges::min({
		// 				costs[0] + rx(find_index(days[index] +  1), 0),
		// 				costs[1] + rx(find_index(days[index] +  7), 1),
		// 				costs[2] + rx(find_index(days[index] + 30), 2)
		// 			});
		// 	}
		// 	return 0;
		// };

		// return rx(0, 0);
    }
};
