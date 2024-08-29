



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::vector<int> bits;
    std::vector<std::vector<int>> dp;
public:
    int dfs(int const &r, int const &c, int const &mask, int const &row) {
	if(dp[mask][row] != -1) { return dp[mask][row]; }
	int ans = 0, count = 0, nxt = 0;
	for(int i = 0; i < (1 << c); ++i) {
	    if((i | mask) == mask and (i & (i << 1)) == 0) { 
		count = __builtin_popcount(i);
		if(row == r-1) {
		    ans = std::max(ans, count);
		} else {
		    nxt = bits[row + 1];
		    nxt = nxt & ~(i >> 1);
		    nxt = nxt & ~(i << 1);
		    ans = std::max(ans, count + dfs(r, c, nxt, row + 1));
		}
	    }
	}
	
	return dp[mask][row] = ans;
    }
    
    int maxStudents(vector<vector<char>>& seats) {
        int const r = seats.size(), c = seats[0].size();
	bits.resize(r);
	dp.resize(1 << c, std::vector<int>(r, -1));
	for(int i = 0; i < r; ++i) {
	    for(int j = 0; j < c; ++j) {
		if(seats[i][j] == '.') {
		    bits[i] = bits[i] | (1 << j);
		}
	    }
	}
	
	return dfs(r, c, bits[0], 0);
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<char>> seats = {{'#','.','#','#','.','#'},{'.','#','#','#','#','.'},{'#','.','#','#','.','#'}};
    std::fprintf(stdout, "%d\n", sol.maxStudents(seats));



    return 0;                
}
