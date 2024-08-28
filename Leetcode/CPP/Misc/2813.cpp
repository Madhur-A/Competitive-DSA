



#include <bits/stdc++.h>
#include <ranges>

using std::vector;

class Solution {
public:
    std::unordered_set<int> seen;
    std::vector<int> copies;
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int const n = items.size();
	std::ranges::sort(items, [](std::vector<int> const &a, std::vector<int> const &b){ return a[0] > b[0]; });
	unsigned long res = 0, ans = 0;

	for(int i = 0; i < k; ++i) {
	    res += items[i][0];
	    if(seen.count(items[i][1])) {
		copies.push_back(items[i][0]);
	    } else {
		seen.insert(items[i][1]);
	    }
	}

	ans = res + (seen.size() * seen.size());

	for(int i = k; i < n; ++i) {
	    if(not seen.count(items[i][1]) and not copies.empty()) {
		seen.insert(items[i][1]);
		res += items[i][0] - copies.back();
		copies.pop_back();
		ans = std::max(ans, res + (seen.size() * seen.size()));
	    }
	}
	

	return ans;
    }
};

int main() {
    std::vector<std::vector<int>> items = {{3,2},{5,1},{10,1}};
    int k = 2;
    Solution sol;
    std::fprintf(stdout, "%lld\n", sol.findMaximumElegance(items, k));


    return 0;
}
