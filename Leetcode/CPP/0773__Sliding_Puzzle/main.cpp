



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static std::string const desired = "123450";
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    std::unordered_set<std::string> visited;
    std::queue<std::string> t;
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int const r = board.size(), c = board[0].size();
        int ans = 0;
        std::string res;
        for(int i = 0; i < r; ++i) { for(int j = 0; j < c; res += board[i][j] + '0', ++j); }

        if(res == desired) { return ans; }

        t.push(res);
        while(not t.empty()) {
            int const z = t.size();
            ans += 1;
            for(int l = 0; l < z; ++l) {
                std::string p = t.front(); t.pop();
                if(p == desired) { return ans; }
                if(not visited.count(p)) {
                    visited.insert(p);
                    int const f = p.find('0');
                    int const i = f / c, j = f % c;
                    for(direction const &dir: dirs) {
                        int const h = dir.first + i, k = dir.second + j;
                        if(h >= 0 and k >= 0 and h < r and k < c) {
                            int const g = c * h + k;
                            std::swap(p[f], p[g]);
                            if(p == desired) { return ans; }
                            t.push(p);
                            std::swap(p[f], p[g]);
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
    std::vector<std::vector<int>> board = {{4,1,2},{5,0,3}};    
    std::fprintf(stdout, "%d\n", sol.slidingPuzzle(board));


    return 0;
}
