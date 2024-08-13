



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    std::unordered_set<unsigned long> visited;
    std::queue<unsigned long> t;
public:
    int minFlips(vector<vector<int>>& mat) {
        int const r = mat.size(), c = mat[0].size();
        int res = 0, z = 0;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(mat[i][j]) { z |= (1UL << (c * i + j)); }
            }
        }
        if(z == 0) { return 0; }
        t.push(z);
        while(not t.empty()) {
            res += 1;
            int const z = t.size();
            for(int l = 0; l < z; ++l) {
                int const p = t.front(); t.pop();
                if(p == 0) { return res-1; }
                if(not visited.count(p)) {
                    visited.insert(p);
                    for(int i = 0; i < r; ++i) {
                        for(int j = 0; j < c; ++j) {
                            int child = p ^ 1UL << (c * i + j);
                            for(direction const &dir: dirs) {
                                int const h = dir.first + i, k = dir.second + j;
                                if(h >= 0 and k >= 0 and h < r and k < c) {
                                    child = child ^ 1UL << (c * h + k);
                                }
                            }
                            t.push(child);
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
    std::vector<std::vector<int>> matrix = {{0,0},{0,1}};    
    std::fprintf(stdout, "%d\n", sol.minFlips(matrix));


    return 0;
}
