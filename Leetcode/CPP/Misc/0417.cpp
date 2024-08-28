



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    std::vector<std::vector<bool>> vis_p, vis_a;
    std::queue<std::pair<int, int>> tp, ta;
public:
    void bfs(vector<vector<int>>& heights, std::queue<std::pair<int, int>> &t, std::vector<std::vector<bool>> &visited) {
        int const r = heights.size(), c = heights[0].size();
        while(not t.empty()) {
            int const x = t.front().first, y = t.front().second; t.pop();
            if(not visited[x][y]) {
                visited[x][y] = true;
                for(direction const &dir: dirs) {
                    int const h = dir.first + x, k = dir.second + y;
                    if(h >= 0 and k >= 0 and h < r and k < c and not visited[h][k]) {
                        if(heights[h][k] >= heights[x][y]) {
                            t.push({h, k});    
                        }
                    }
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int const r = heights.size(), c = heights[0].size();
        vis_p.resize(r, std::vector<bool>(c));
        vis_a.resize(r, std::vector<bool>(c));
        for(int i =  0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(i == 0 or j == 0) { tp.push({i, j}); }
                if(i == r-1 or j == c-1) { ta.push({i, j}); }
            }
        }
        bfs(heights, tp, vis_p);
        bfs(heights, ta, vis_a);
        
        std::vector<std::vector<int>> ans;
        
        for(int i =  0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(vis_a[i][j] == true and vis_p[i][j] == true) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;        
    }
};

int main() {
    std::vector<std::vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution sol;
    std::vector<std::vector<int>> ans = sol.pacificAtlantic(heights);
    for(std::vector<int> const &row: ans) {
	std::cout << "[" << row[0] << ", " << row[1] << "] ";
    }
    std::cout << '\n';


    return 0;
}
