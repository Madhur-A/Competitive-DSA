



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> t;
public:
    long long maxSpending(vector<vector<int>>& values) {
        int const r = values.size(), c = values[0].size();
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                t.push(values[i][j]);
            }
        }

        long res = 0L, d = 1L;
        while(not t.empty()) {
            res += (t.top() * d);
            d += 1L;
            t.pop();
        }
        return res;
    }
};

int main() {
    std::vector<std::vector<int>> values = {{8,5,2},{6,4,1},{9,7,3}};
    Solution sol;
    std::fprintf(stdout, "%lld\n", sol.maxSpending(values));


    return 0;
}
