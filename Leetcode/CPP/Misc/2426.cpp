



#include <bits/stdc++.h>

using std::vector;

struct fenwick {
public:
    int n;
    std::vector<int> v;
public:
    fenwick(int const &n): n(n+1), v(n+1) {
    }
    void update(int const &i, int const &val) {
	int index = i;
	while(index < n) {
	    v[index] += val;
	    index = index + (index & -index);
	}
    }
    int sum(int const &i) {
	int index = i, res = 0;
	while(index) {
	    res += v[index];
	    index = index - (index & -index);
	}
	return res;
    }
};

class Solution {
public:
    inline static constexpr int const max_size = 1000000;
    inline static constexpr int const    delta = 555555;
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
	int const n = nums1.size();
        fenwick f(max_size);
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
	    int const val = nums1[i] - nums2[i];
	    ans += f.sum(val + diff + delta);
	    f.update(val + delta, 1);
	}
	return ans;
    }
};

int main() {
    std::vector<int> nums1 = {3,2,5}, nums2 = {2,2,1};
    int diff = 1;
    Solution sol;
    std::fprintf(stdout, "%lld\n", sol.numberOfPairs(nums1, nums2, diff));
    

    return 0;
}
