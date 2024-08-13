



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    using direction = std::pair<int, int>;
    using   element = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    std::queue<element> t;
    std::vector<std::vector<bool>> visited;
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int const r = grid.size(), c = grid[0].size();
        int target = 0, start = 0, ans = 0;

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                char const ch = grid[i][j];
                target += (ch >= 'a' and ch <= 'f');
                start = (ch == '@') ? i * c + j : start;
            }
        }

        visited.resize(r*c + c + 0UL + 1, std::vector<bool>(1 << target));
        t.push({start, 0});

        while(not t.empty()) {
            int const z = t.size();
            ans += 1;
            for(int l = 0; l < z; ++l) {
                element const p = t.front(); t.pop();
                int const x = p.first, found = p.second;
                int const i = x / c, j = x % c;

                if(found == (1 << target) - 1) { return ans - 1; }

                if(not visited[x][found]) {
                    visited[x][found] = true;
                    for(direction const &dir: dirs) {
                        int const h = dir.first + i, k = dir.second + j;
                        int const q = h * c + k;
                        if(h >= 0 and k >= 0 and h < r and k < c and grid[h][k] != '#') {
                           if(not (std::isupper(grid[h][k]) and not (found >> (grid[h][k] - 'A') & 1))) {
                                std::islower(grid[h][k]) ?
                                    t.push({q, found | (1 << (grid[h][k] - 'a'))}) : t.push({q, found});
                           }
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
    std::vector<std::string> grid = {"@.a..","###.#","b.A.B"};    
    std::fprintf(stdout, "%d\n", sol.shortestPathAllKeys(grid));


    return 0;
}
