


#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
    inline static constexpr int       const always  = 1000000000;
public:
    std::vector<std::vector<bool>> visited;
    std::deque<std::pair<int, int>> t, f;
public:
    std::deque<std::pair<int, int>> incinerate(vector<vector<int>> const &grid, std::vector<std::vector<bool>> &fired) {
        int const r = grid.size(), c = grid[0].size();
        std::deque<std::pair<int, int>> w;
        while(not f.empty()) {
            std::pair<int, int> const p = f.front(); f.pop_front();
            int const i = p.first, j = p.second;
            for(direction const &dir: dirs) {
                int const h = dir.first + i, k = dir.second + j;
                if(h >= 0 and k >= 0 and h < r and k < c and grid[h][k] == 0 and not fired[h][k]) {
                    w.push_back({h, k});
                    fired[h][k] = true;
                }
            }
        }

        f.clear();
        return w;
    }
    
    bool condition(vector<vector<int>>& grid, int const &minutes) {
        int const r = grid.size(), c = grid[0].size();	
        visited.clear();
        f.clear(); t.clear();
        std::vector<std::vector<bool>> fired(r, std::vector<bool>(c));
        visited.resize(r, std::vector<bool>(c));

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] == 1) {
                    f.push_back({i, j});
                    fired[i][j] = true;
                }
            }
        }
        
        int m = minutes;
        while(m and not f.empty()) {
            f = incinerate(grid, fired);
            m = m - 1;
        }

        t.push_back({0, 0});

        while(not t.empty()) {
            int const z = t.size();
            for(int l = 0; l < z; ++l) {
                std::pair<int, int> const p = t.front(); t.pop_front();
                int const i = p.first, j = p.second;
                if(i == r-1 and j == c-1) { return true; }
                if(not visited[i][j] and not fired[i][j]) {
                    visited[i][j] = true;
                    for(direction const &dir: dirs) {
                        int const h = dir.first + i, k = dir.second + j;
                        if(h >= 0 and k >= 0 and h < r and k < c and grid[h][k] == 0 and not visited[h][k] and not fired[h][k]) {
                            t.push_back({h, k});
                        }
                    }
                }
            }
            f = incinerate(grid, fired);
        }
        return false;
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        int left = -1, right = r*c, mid = 0;
        while(left < right) {
            mid = (left + right + 1) >> 1;
            if(condition(grid, mid)) {
                left  = mid;
            } else {
                right = mid - 1;
            }
        }
        return (left == r*c) ? always : left;
    }
    
};

int main() {    
    std::vector<std::vector<int>> grid = {{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.maximumMinutes(grid));


    return 0;
}
