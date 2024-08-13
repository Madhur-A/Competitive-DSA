



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using element = std::tuple<long, long, long>;
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        long pfx_sum = 0L;
        std::vector<element> stack = {{0L, 0L, 0L}};

		for(int i = 0, j = 0; i < n; ++i) {
			pfx_sum += nums[i];

			while(j+1 < stack.size() and pfx_sum >= std::get<0>(stack[j+1])) { ++j; }

            element const p = stack[j];
            long const curr = std::get<1>(p), dp = std::get<2>(p);

			long const last = pfx_sum - curr;
			while(not stack.empty() and std::get<0>(stack.back()) >= last+pfx_sum) { stack.pop_back(); }
			stack.push_back({last+pfx_sum, pfx_sum, dp+1});
		}

        return std::get<2>(stack.back());
    }
};

int main() {
    std::vector<int> nums = {4,3,2,6};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.findMaximumLength(nums));

    return 0;
}
