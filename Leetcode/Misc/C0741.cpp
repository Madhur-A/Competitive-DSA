



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    inline static constexpr int const inf = 1000000;
public:
    std::vector<std::vector<int>> dp;
public:
    int dfs(std::vector<std::vector<int>> &grid, int dr /*down right*/, int ul /*up left*/, int c) {
	int const i = dr / c, j = dr % c;
	int const h = ul / c, k = ul % c;
	if(i >= 0 and h >= 0 and j < c and k < c) {
	    if(i == c-1 and j == c-1) { return grid[i][j]; }
	    if(h ==   0 and k ==   0) { return grid[h][k]; }
	    if(dp[i][j] != -inf) {
		return dp[i][j];
	    }
	    int const down_right = grid[i][j], up_left = grid[h][k];
	    return dp[dr][ul] = 
		std::max(
		    down_right + std::max(dfs(grid, (i+1)*c + j, ul, c), dfs(grid, i*c + (j+1), ul, c)),
		    up_left    + std::max(dfs(grid, dr, (h-1)*c + k, c), dfs(grid, dr, h*c + (k-1), c))
		    );
	}
	return -inf;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
	int const r = grid.size(), c = grid[0].size();
	dp.resize(r*c + 1, std::vector<int>(r*c + 1, -inf));
	return dfs(grid, 0, r*c - 1, c);
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{0,1,1,0,0},{1,1,1,1,0},{-1,1,1,1,-1},{0,1,1,1,0},{1,0,-1,0,0}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.cherryPickup(grid));


    return 0;
}
