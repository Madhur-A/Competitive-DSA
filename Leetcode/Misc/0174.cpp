



#include <bits/stdc++.h>

using std::vector;

class Solution {  
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[2] =  {{0,1},{1,0}};
    inline static constexpr int       const     inf =  1999999999;
public:
    int dp[201][201];
public:
    int dfs(vector<vector<int>>& grid, int const &i, int const &j) {
	int const r = grid.size(), c = grid[0].size();
	if(i >= 0 and j >= 0 and i < r and j < c) {
	    if(i == r-1 and j == c-1) {
		return grid[i][j] > 0 ? 1 : std::abs(grid[i][j]) + 1;
	    }
	    if(dp[i][j] != -1) { return dp[i][j]; }
	    int res = inf;
	    for(direction const &dir: dirs) {
		res = std::min(res, dfs(grid, dir.first + i, dir.second + j));
	    }
	    return dp[i][j] = res - grid[i][j] > 0 ? res - grid[i][j] : 1;
	}
	return inf;
    }
	    
    int calculateMinimumHP(vector<vector<int>>& grid) {
	memset(dp, -1, sizeof(dp));
	return dfs(grid, 0, 0);
    }
};

int main() {
    std::vector<std::vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.calculateMinimumHP(dungeon));


    return 0;
}
