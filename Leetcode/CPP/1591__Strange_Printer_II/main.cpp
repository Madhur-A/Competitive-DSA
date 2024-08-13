



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, std::vector<int>> g;
    std::unordered_set<int> colors;
    std::vector<int> visited;
public:
    bool is_valid(vector<vector<int>> &grid, int color) {
        visited[color] = 1;
        for(int i = g[color][0]; i <= g[color][2]; ++i) {
            for(int j = g[color][1]; j <= g[color][3]; ++j) {
                if(grid[i][j] != color) {
                    if(visited[grid[i][j]] == 1) { return false; }
                    if(visited[grid[i][j]] == 0 and not is_valid(grid, grid[i][j])) {
                        return false;
                    }
                }
            }
        }
        visited[color] += 1; // [!]rendered redundant
        return true;
    }

    bool isPrintable(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        visited.resize(r*c + 1, -1);
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                int const color = grid[i][j];
                colors.insert(color);
                if(not g.count(color)) {
                    g[color] = {i, j, i, j};
                    visited[color] = 0;
                } else {
                    g[color][0] = std::min(g[color][0], i);
                    g[color][1] = std::min(g[color][1], j);
                    g[color][2] = std::max(g[color][2], i);
                    g[color][3] = std::max(g[color][3], j);
                }
            }
        }
        for(int const &color: colors) {
            if(not is_valid(grid, color)) { return false; }
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid = {{1,1,1,1},{1,2,2,1},{1,2,2,1},{1,1,1,1}};    
    std::cout.setf(std::ios::boolalpha);
    std::cout << sol.isPrintable(grid) << '\n';


    return 0;
}
