



int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    std::vector<std::vector<int>> visited;
public:
    bool is_valid(int i, int j, vector<vector<int>>& g) {
        return (i >= 0 and i < g.size() and j >= 0 and j < g[0].size());
    }
    bool rx(vector<vector<int>>& G, vector<vector<int>>& H, int x, int y) {
		if(G[x][y] != 1) { visited[x][y] = -1; return false; }
		visited[x][y] = 1;
		for(direction const &dir: dirs) {
			int const h = x + dir.first, k = y + dir.second;
			if(is_valid(h, k, G) and visited[h][k] != 1) {
				if(visited[h][k] == -1) { visited[x][y] = -1; return false; }
				if(H[h][k] == 1 and rx(G, H, h, k) == false) {
					visited[x][y] = -1;
					return false;
				}
			}
        }

        return true;
    }
    
    int countSubIslands(vector<vector<int>>& g, vector<vector<int>>& h) {
        int const r = g.size(), c = g[0].size();
        int ans = 0;
        visited.resize(r, std::vector<int>(c));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(visited[i][j] == 0 and h[i][j] and rx(g, h, i, j)) {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};
