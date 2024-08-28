



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_set<long> lighted;
    std::unordered_map<int, int> rows, cols, dl, du;
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        for(std::vector<int> const &lamp: lamps) {
            int const i = lamp[0], j = lamp[1];
            if(not lighted.count(i * 1L * n + j)) {
                rows[i] += 1; cols[j] += 1;
                dl[i - j] += 1;
                du[i + j] += 1;
                lighted.insert(i * 1L * n + j);
            }
        }

        std::vector<int> ans(queries.size());
        int q = 0;
        for(std::vector<int> const &query: queries) {
            int const r = query[0], c = query[1];
            if(rows[r] > 0 or cols[c] > 0 or dl[r - c] > 0 or du[r + c] > 0) { ans[q] = 1; }
            for(int i = r-1; i <= r+1; ++i) {
                for(int j = c-1; j <= c+1; ++j) {
                    long const pos = i * 1L * n + j;
                    if(i >= 0 and j >= 0 and i < n and j < n and lighted.count(pos)) {
                        dl[i - j] -= 1; du[i + j] -= 1;
                        rows[i] -= 1; cols[j] -= 1;
                        lighted.erase(pos);
                    }
                }		
            }
            q += 1;
        }

        return ans;	
    }
};

int main() {
    int n = 5;
    std::vector<std::vector<int>> lamps = {{0,0},{4,4}}, queries = {{1,1},{1,0}};
    Solution sol;
    std::vector<int> res = sol.gridIllumination(n, lamps, queries);
    std::ranges::copy(res, std::ostream_iterator<int>(std::cout, " "));
    std::putc('\n', stdout);


    return 0;    
}
