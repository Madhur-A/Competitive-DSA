



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& grid, int max_area) {
        int const r = grid.size(), c = grid[0].size();
        int ans = INT_MIN;
        std::vector<int> cols(c);
        std::set<int> sigma;
        for(int i = 0; i < r; ++i) {
            cols.clear(); cols.resize(c);
            for(int j = i; j < r; ++j) {
                for(int k = 0; k < c; ++k) {
                    cols[k] += grid[j][k];
                }
                int curr = 0;
                sigma.clear();
                sigma.insert(curr);
                for(int const &sum: cols) {
                    curr += sum;
                    std::set<int>::const_iterator it = sigma.lower_bound(curr-max_area);
                    if(it != sigma.end()) {
                        ans = std::max(ans, curr - *it);
                    }
                    if(ans == max_area) { sigma.clear(); return ans; }
                    sigma.insert(curr);
                }
            }
        } return ans;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{1,0,1},{0,-2,3}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.maxSumSubmatrix(grid, 2));


    return 0;
}
