



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& txns) {
//        int const n = txns.size();
        long long ans = 0, max_possible = 0;
        std::ranges::for_each(txns, [&](std::vector<int> const &txn) {
            max_possible += std::max(0, txn[0] - txn[1]);
        });
        std::ranges::for_each(txns, [&](std::vector<int> const &txn){
            if(txn[0] > txn[1]) {
                ans = std::max(ans, txn[1] + max_possible);
            } else {
                ans = std::max(ans, txn[0] + max_possible);
            }
        });

        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> txns = {{2,1},{5,0},{4,2}};    
    std::fprintf(stdout, "%lld\n", sol.minimumMoney(txns));


    return 0;
}
