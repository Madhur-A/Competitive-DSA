



#include <bits/stdc++.h>
#include <set>

using std::vector;
using std::set;
using std::min, std::max;

class Solution {
public:    
    std::vector<int> c_sums;
    std::vector<int> prefix;
public:
    int ans = INT_MIN;
public:
    int ansSubgrid(vector<vector<int>>& grid, int target) {
        int const r = grid.size(), c = grid[0].size();
	c_sums.resize(c);
	prefix.resize(c);
      
        for(int i = 0; i < r; ++i) {
            for(int h = i; h < r; ++h) {
                for(int j = 0; j < c; ++j) {
                    c_sums[j] += grid[h][j];
                }
		std::partial_sum(c_sums.begin(), c_sums.end(), prefix.begin());

		int left = -target-1, right = prefix[c-1], mid = 0;
		while(left <= right) {
		    mid = left + ((right - left) >> 1);
		    if(mid < target) {
			left  = mid + 1;			
		    } else {			
			right = mid - 1;
		    }
		}

		ans = std::max(ans, left);
	    }
	}
	
        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{8,3,3,3,8},{5,1,6,6,1},{1,5,2,9,4},{2,5,9,2,3},{5,4,3,1,7}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.ansSubgrid(grid, 46));
}

//gcc-13-locales g++-13-multilib gcc-13-multilib
