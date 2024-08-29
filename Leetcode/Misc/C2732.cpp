



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> g;
public:
    int get_mask(std::vector<int> const &row) {
	int res = 0;
	for(unsigned long i = 0; i < row.size(); ++i) {
	    res = (row[i] == 1) ? res | (1 << i) : res;
	}
	return res;
    }
    
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        for(unsigned long i = 0; i < grid.size(); ++i) {
	    int const mask = get_mask(grid[i]);
	    if(not mask) { return { (int)i }; }
	    for(int p = 1; p < 32; ++p) {
		if(not (p & mask) and g.count(p)) { return { g[p], (int)i}; }
	    }
	    g[mask] = i;
	}
	return {};
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{0,1,1,0},{0,0,0,1},{1,1,1,1}};
    Solution sol;
    std::ranges::copy(sol.goodSubsetofBinaryMatrix(grid), std::ostream_iterator<int>(std::cout, " "));
    std::putc('\n', stdout);


    return 0;
}
