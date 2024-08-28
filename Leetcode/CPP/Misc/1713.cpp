



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> g;
    std::vector<int> ans;
public:
    int lengthOfLIS(vector<int> const &nums) {
        int const n = nums.size();
        ans.push_back(nums[0]);
        for(int i = 1; i < n; ++i) {
            int const num = nums[i];
            if(num > ans.back()) {
                ans.push_back(num);
            } else {
                int left = 0, right = ans.size();
                while(left < right) {
                    int const mid = left + ((right - left) >> 1);
                    if(ans[mid] < num) {
                        left  = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                ans[left] = num;
            }
        }
        return ans.size();
    }
    
    int minOperations(vector<int>& target, vector<int>& arr) {
        int const n = arr.size(), m = target.size();
        std::vector<int> nums;
        for(int i = 0; i < m; ++i) { g[target[i]] = i; }
        for(int i = 0; i < n; ++i) { if(g.count(arr[i])) { nums.push_back(g[arr[i]]); } }
        return m - (nums.empty() ? 0 : lengthOfLIS(nums));
    }
};

int main() {
    std::vector<int> target = {5,1,3}, arr = {9,4,2,3,4};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minOperations(target, arr));


    return 0;
}
