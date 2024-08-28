



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using longest = long long;
public:
    std::vector<std::pair<int, int>> values;
    std::vector<longest> prefix_mux, prefix_exp;
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
	int const n = nums.size();
	values.resize(n); prefix_mux.resize(n+1); prefix_exp.resize(n+1);
	for(int i = 0; i < n; ++i) { values[i] = {nums[i], cost[i]}; }
	std::ranges::sort(values);

	for(int i = 1; i < n+1; ++i) {
	    int const num = values[i-1].first, exp = values[i-1].second;
	    prefix_mux[i] = prefix_mux[i-1] + num * 1LL * exp;
	    prefix_exp[i] = prefix_exp[i-1] + exp;
	}

	longest ans = LLONG_MAX, left = 0, right = 0;
	
	for(int i = 1; i < n+1; ++i) {
	    int const num = values[i-1].first;
	    left = num * 1LL * prefix_exp[i-1] - prefix_mux[i-1];
	    right = prefix_mux[n] - prefix_mux[i] - num * 1LL * (prefix_exp[n] - prefix_exp[i]);
	    ans = std::min(ans, left + right);
	}
	

        return ans;
    }
};

int main() {
    std::vector<int> nums = {1,3,5,2};
    std::vector<int> cost = {2,3,1,14};
    Solution sol;
    std::fprintf(stdout, "%lld\n", sol.minCost(nums, cost));


    return 0;
}
