



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    inline static constexpr int const mod = 1000000007;
public:
    int dp[51][51][11];
    std::vector<std::vector<int>> prefix;
public:
    int dfs(int const &i, int const &j, int const &rem) {
	int const r = prefix.size()-1, c = prefix[0].size()-1;	
	if(rem == 0) {
	    return (prefix[i][j] + prefix[r][c] - prefix[i][c] - prefix[r][j]) > 0;
	}
	if(dp[i][j][rem] != -1) { return dp[i][j][rem]; }
	int res = 0;
	for(int h = i+1; h < r; ++h) {
	    if((prefix[i][j] + prefix[h][c] - prefix[i][c] - prefix[h][j]) > 0) {
		res += dfs(h, j, rem-1);
		res %= mod;
	    }
	}
	for(int k = j+1; k < c; ++k) {	    
	    if((prefix[i][j] + prefix[r][k] - prefix[i][k] - prefix[r][j]) > 0) {
		res += dfs(i, k, rem-1);
		res %= mod;
	    }
	}
	return dp[i][j][rem] = res;
    }
    
    int ways(vector<string>& pizza, int apples) {
	int const r = pizza.size(), c = pizza[0].size();
        memset(dp, -1, sizeof(dp));
	prefix.resize(r + 1, std::vector<int>(c + 1));
	for(int i = 1; i < r+1; ++i) {
	    for(int j = 1; j < c+1; ++j) {
		prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + (pizza[i-1][j-1] == 'A');
	    }
	}
	return dfs(0, 0, apples-1);
    }
};

int main() {
    std::vector<std::string> pizza = {"AA.","AAA","..."};
    int k = 3;
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.ways(pizza, k));


    return 0;
}
