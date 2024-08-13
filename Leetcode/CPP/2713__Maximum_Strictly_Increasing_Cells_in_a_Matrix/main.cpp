



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::map<int, std::vector<int>> g;
    std::vector<int> r_max, c_max, res;
public:
    int maxIncreasingCells(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        int ans = 0;

        r_max.resize(r); c_max.resize(c);

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                g[grid[i][j]].push_back(i * c + j);
            }
        }

        for(std::pair<int const, std::vector<int>> const &node: g) {
            res.clear();
            for(int const &position: node.second) {
                int const i = position / c, j = position % c;
                res.push_back(std::max(r_max[i], c_max[j]) + 1);
                ans = std::max(ans, res.back());
            }
            for(int l = 0; l < res.size(); ++l) {
                int const h = node.second[l] / c, k = node.second[l] % c;
                r_max[h] = std::max(r_max[h], res[l]);
                c_max[k] = std::max(c_max[k], res[l]);
            }
        }

        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{3,1,6},{-9,5,7}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.maxIncreasingCells(grid));


    return 0;
}
