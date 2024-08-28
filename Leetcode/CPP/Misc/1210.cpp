



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using element = std::tuple<int, int, int>; // i, j, 0/1
public:
    std::queue<element> t;
    std::set<element> visited;
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        t.push({0, 1, 1});
        int res = 0;
        while(not t.empty()) {
            int const z = t.size();
            res += 1;
            for(int l = 0; l < z; ++l) {
                element const popped = t.front(); t.pop();
                int const i = std::get<0>(popped), j = std::get<1>(popped);
                int const orientation = std::get<2>(popped);
                if(i == r-1 and j == c-1 and orientation) { return res - 1; }
                if(not visited.count(popped)) {
                    visited.insert(popped);
                    if(orientation) {	// right-side
                        if(j+1 < c and grid[i][j+1] == 0) { t.push({  i, j+1, 1 }); }
                        if(i+1 < r and j > 0 and grid[i+1][j] == 0 and grid[i+1][j-1] == 0) {
                            t.push({  i+1, j+0, 1 });
                            t.push({  i+1, j-1, 0 }); 
                        }			
                    } else { // doown-town
                        if(i+1 < r and grid[i+1][j] == 0) { t.push({  i+1, j, 0 }); }
                        if(j+1 < c and i > 0 and grid[i][j+1] == 0 and grid[i-1][j+1] == 0) {
                            t.push({  i+0, j+1, 0 });
                            t.push({  i-1, j+1, 1 }); 
                        }						
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    std::vector<std::vector<int>>	
    grid = {{0,0,0,0,0,1},
    	    {1,1,0,0,1,0},
    	    {0,0,0,0,1,1},
    	    {0,0,1,0,1,0},
    	    {0,1,1,0,0,0},
    	    {0,1,1,0,0,0}};

    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minimumMoves(grid));


    return 0;
}
