



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using element = std::tuple<int, int, int>;
    using p_queue = std::priority_queue<element, std::vector<element>, std::greater<element>>;
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
        int const r = grid.size(), c = grid[0].size();

        std::vector<std::vector<bool>> visited(r+1, std::vector<bool>(c+1));

        p_queue t, right, down;
        t.push({0, 0, 0});
        int h = 0, k = 0;
        while(not t.empty()) {
            element const p = t.top(); t.pop();
            int const s = std::get<0>(p), x = std::get<1>(p), y = std::get<2>(p);
            if(x == r-1 and y == c-1) { return s + 1;  }
            if(not visited[x][y]) {
                visited[x][y] = true;
                int const d_bound = std::min(grid[x][y] + x, r-1), r_bound = std::min(grid[x][y] + y, c-1);
                k = r_bound;
                while(k > y and right.size() <= 7) {
                    if(not visited[x][k]) {
                        if(x == r-1 and k == c-1) { return s+2; }
                        right.push({s+1, x, k});
                    }
                    k = k - 1;
                }
                h = d_bound;
                while(h > x and down.size() <= 7) {
                    if(not visited[h][y]) {
                        if(h == r-1 and y == c-1) {return s+2; }
                        down.push({s+1, h, y});
                    }
                    h = h - 1;
                }

                if(down.empty()) {
                    while(not right.empty()) { t.push(right.top()); right.pop(); }
                } else if(right.empty()) {
                    while(not down.empty()) { t.push(down.top()); down.pop(); }
                } else {
                    while(not right.empty() or not down.empty()) {
                        if(not down.empty()) {
                            t.push(down.top()); down.pop();
                        }
                        if(not right.empty()) {
                            t.push(right.top()); right.pop();
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid = {{3,4,2,1},{4,2,1,1},{2,1,1,0},{3,4,1,0}};    
    std::fprintf(stdout, "%d\n", sol.minimumVisitedCells(grid));


    return 0;
}
