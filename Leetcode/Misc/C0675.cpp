



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
    using   element = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};    
public:
    std::priority_queue<element, std::vector<element>, std::greater<element>> t;
    std::deque<element> u;
public:
    int cutOffTree(vector<vector<int>>& forest) {
	int const r = forest.size(), c = forest[0].size();
        for(int i = 0; i < r; ++i) {
	    for(int j = 0; j < c; ++j) {
		if(forest[i][j] != 0 and forest[i][j] != 1) {
		    t.push({forest[i][j], i*c + j});
		}
	    }
	}
	int ans = 0;
	u.push_back({0, 0});
	std::vector<std::vector<bool>> visited(r, std::vector<bool>(c));
	while(not t.empty()) {
	    element const popped = t.top(); t.pop();
	    int const height = popped.first;
	    int const dest_x = popped.second / c, dest_y = popped.second % c;
	    std::fprintf(stdout, "%d, %d, %d\n", height, dest_x, dest_y);
	    bool res = false;
	    while(not u.empty() and not res) {
		element const p = u.front(); u.pop_front();
		int const x = p.first, y = p.second;
		if(x == dest_x and y == dest_y) { res = true; forest[dest_x][dest_y] = 1; u.clear(); break; }
		if(not visited[x][y] and not res) {
		    visited[x][y] = true;
		    for(direction const &dir: dirs) {
			int const h = dir.first + x, k = dir.second + y;
			if(h >= 0 and k >= 0 and h < r and k < c) {
			    if(not visited[h][k] and forest[h][k] != 0 and (forest[h][k] == 1 or forest[h][k] <= height)) {
				u.push_back({h, k});
			    }
			}
		    }
		}
		ans += 1;
	    }
	    if(not res) { std::fprintf(stdout, "[%s]\n", "breaking!"); break; }
	    u.clear();
	    u.push_back({dest_x, dest_y});
	}
	
	return t.empty() ? ans : -1;
    }
};

int main() {
    std::vector<std::vector<int>> forest = {{1,2,3},{0,0,0},{7,6,5}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.cutOffTree(forest));


    return 0;
}
