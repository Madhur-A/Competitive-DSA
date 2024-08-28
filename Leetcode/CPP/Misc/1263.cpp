



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
    using   element = std::tuple<int, int, int>; // distance, person, box
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}}; // R, D, L, U
public:
    std::vector<std::vector<bool>> visited;
    // std::queue<element> t;
    std::priority_queue<element, std::vector<element>, std::greater<element>> t;
public:
    int minPushBox(vector<vector<char>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        visited.resize(r*c, std::vector<bool>(r*c));
	    int person_i = 0, box_i = 0;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] == 'S') { person_i = i*c + j; }
		        if(grid[i][j] == 'B') { box_i    = i*c + j; }
            }
        }
        t.push({0, person_i, box_i});
        while(not t.empty()) {
            element const p = t.top(); t.pop();
            int const distance = std::get<0>(p), person = std::get<1>(p), box = std::get<2>(p);
            int const pi = person / c, pj = person % c;
            int const bi = box / c,    bj = box % c;
            if(grid[bi][bj] == 'T') { return distance; }
            if(not visited[person][box]) {
                visited[person][box] = true;
                for(direction const &dir: dirs) {
                    int const ph = pi + dir.first, pk = pj + dir.second;
                    int const pn = ph*c + pk;
                    if(ph >= 0 and pk >= 0 and ph < r and pk < c and grid[ph][pk] != '#' and not visited[pn][box]) { // valid
                        if(ph == bi and pk == bj) { // try moving the box
                            int const bh = bi + dir.first, bk = bj + dir.second;
                            int const bn = bh*c + bk;
                            if(bh >= 0 and bk >= 0 and bh < r and bk < c and grid[bh][bk] != '#' and not visited[pn][bn]) {
                                t.push({distance+1, pn, bn});
                            }
                        } else {
                            t.push({distance, pn, box}); // box not found yet, keep on moving
                        }
                    }
                }
            }
        } return -1;
    }
};

int main() {
    std::vector<std::vector<char>> grid = {{'#','#','#','#','#','#'},
					   {'#','T','#','#','#','#'},
					   {'#','.','.','B','.','#'},
					   {'#','.','#','#','.','#'},
					   {'#','.','.','.','S','#'},
					   {'#','#','#','#','#','#'}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minPushBox(grid));


    return 0;
}
