



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& txns) {
	long long max_possible = 0LL, ans = 0LL;
	for(std::vector<int> const &txn: txns) { max_possible += std::max(0, txn[0] - txn[1]); }
	for(std::vector<int> const &txn: txns) {
	    if(txn[0] > txn[1]) {
		ans = std::max(ans, max_possible + txn[1]);
	    } else {
		ans = std::max(ans, max_possible + txn[0]);
	    }
	}
	return ans;
    }
};

int main() {
    std::vector<std::vector<int>> txns = {{2,1},{5,0},{4,2}};
    Solution sol;
    std::fprintf(stdout, "%lld\n", sol.minimumMoney(txns));
}
