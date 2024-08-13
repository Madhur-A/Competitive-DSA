



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int dp(vector<vector<int>> grid) {
        int const r = grid.size(), c = grid[0].size();
        int res = 0;
        for(int i = r - 2; i >= 0; --i) {
            for(int j = 1; j < c - 1; ++j) {
                if(grid[i][j]) {
                    grid[i][j] = std::ranges::min({grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]}) + 1;
                    res += grid[i][j] - 1;
                }
            }
        }
        return res;
    }

    int countPyramids(vector<vector<int>>& grid) {
        int ans = 0;
        ans += dp(grid);
        std::reverse(grid.begin(), grid.end());
        ans += dp(grid);
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid = {{0,1,1,0},{1,1,1,1}};
    std::fprintf(stdout, "%d\n", sol.countPyramids(grid));


    return 0;
}
