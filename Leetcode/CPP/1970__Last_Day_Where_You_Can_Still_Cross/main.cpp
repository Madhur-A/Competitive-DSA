



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    std::vector<bool> visited;
    std::deque<int> t;
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int const n = cells.size();
        int const r = row, c = col;
        int left = 1, right = n - 1, mid = 0;

        while(left <= right) {
            mid = left + ((right - left) >> 1);
            // BFS --start--
            visited.clear(); t.clear();
            visited.resize(r*c + c + 1);
            std::for_each(cells.begin(), cells.begin() + mid, [&](std::vector<int> const &cell){
                int const val = (cell[0] - 1) * c + (cell[1] - 1);
                visited[val] = true;
            });
            for(int j = 0; j < c; ++j) {
                if(not visited[j]) {
                    t.push_back(j);
                }
            }
            bool res = false;
            while(not t.empty() and not res) {
                int const z = t.size();
                for(int l = 0; l < z; ++l) {
                    int const p = t.front(); t.pop_front();
                    int const x = p / c, y = p % c;
                    if(x == r - 1) { res = true; break; }
                    int const rsx = x * c + y;
                    if(not visited[rsx] and not res) {
                        visited[rsx] = true;
                        for(direction const &dir: dirs) {
                            int const h = dir.first + x, k = dir.second + y;
                            int hi_res = h * c + k;
                            if(h >= 0 and k >= 0 and h < r and k < c and not visited[hi_res]) {
                                t.push_back(hi_res);
                            }
                        }
                    }
                }
            }
            // BFS --  end--
            if(res) {
                left  = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};

int main() {
    Solution sol;
    int row = 2, col = 2;
    std::vector<std::vector<int>> cells = {{1,1},{2,1},{1,2},{2,2}};    
    std::fprintf(stdout, "%d\n", sol.latestDayToCross(row, col, cells));


    return 0;
}
