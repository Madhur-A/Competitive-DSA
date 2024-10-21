



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
	inline static constexpr int const inf = INT_MAX;
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int const n = nums.size();
        std::vector<int> prefix(n, inf);

		int left = 0, right = 0, curr = 0;
        int len = 0, res = inf;

		while(right < n) {
			curr += nums[right];
			while(curr > target and left < n) {
				curr = curr - nums[left++];
			}
			len = right - left + 1;
			if(curr == target and left > 0 and prefix[left - 1] != INT_MAX) {
				res = std::min(res, prefix[left - 1] + len);
			}
			prefix[right] = (curr == target) ? std::min(prefix[right], len) : prefix[right];
			prefix[right] = (right > 0) ? std::min(prefix[right], prefix[right - 1]) : prefix[right];
            right += 1;
		}


        return res == inf ? -1 : res;
    }
};

int main() {
	std::vector<int> nums = {4,3,2,6,3,4}; //{7,3,4,7}; //{3,2,2,4,3};
	Solution sol;
	int target = 6;
	std::fprintf(stdout, "%d\n", sol.minSumOfLengths(nums, target));


	return 0;
}
