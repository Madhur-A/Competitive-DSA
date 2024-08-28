



#include <bits/stdc++.h>

class Solution {
public:
    inline static constexpr int const mod = 1000000007;
public:
    std::unordered_map<int, std::vector<int>> hashes;
    int prime_above_hundered = 103;
    int prime_inverse  = 572815538; // modular inverse of prime = 103
public:
    std::vector<int> hash(std::vector<int> const &nums, int const &ln) {
        int const n = nums.size();
        std::vector<int> ans(n - ln + 1);
        long h = 0, power = 1;
        if(ln) {
	    for(int i = 0; i < n; ++i) {
		h = (h + nums[i] * 1LL * power) % mod;
		if(i < ln-1) {
		    power = (power * 1LL * prime_above_hundered) % mod;
		} else {
		    ans[i-ln+1] = h;
		    h = (h - nums[i-ln+1]) * 1LL * prime_inverse % mod;
		}
		h += mod;
	    }
	}
        
        return ans;
    }

    bool condition(std::vector<int> const &nums1, std::vector<int> const &nums2, int const &estimate) {
    	hashes.clear();
        int j = 0, k = 0;
        for(int const &num: hash(nums1, estimate)) { hashes[num].push_back(k); k += 1; }
        for(int const &num: hash(nums2, estimate)) {
            for(int const &i: hashes[num]) {		
                if(std::vector<int>(nums1.begin()+i, nums1.begin()+i+estimate) == 
                   std::vector<int>(nums2.begin()+j, nums2.begin()+j+estimate)) {		    
                    return true;		    
                }			
            } ++j;
        }
        
        return false;	
    }

    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int const n = nums1.size(), m = nums2.size();
        int left = 0, right = std::min(n, m) + 1, mid = 0;
        while(left < right) {
            mid = left + ((right - left) >> 1);	    
            if(condition(nums1, nums2, mid)) {
                left  = mid + 1;		
            } else {
                right = mid;
            }
        }
        return left - 1;
    }    
};


int main() {
    std::vector<int> nums1 = {1,2,3,2,1}, nums2 = {3,2,1,4,7};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.findLength(nums1, nums2));


    return 0;
}
