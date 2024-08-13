



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::vector<std::vector<int>> ans;
    std::vector<int> f;
public:
    void dfs(vector<int>& nums, int curr, int target, int index) {
        int const n = nums.size();
        if(curr == target) { ans.push_back(f); return; }
        if(index >= n)                       { return; }
        if(curr > target)                    { return; }
        if(nums[index] + curr > target)      { return; }

        for(int i = index; i < n; ++i) {
            if(i > index and nums[i] == nums[i-1]) { continue; }
            f.push_back(nums[i]);
            dfs(nums, curr + nums[i], target, i+1);
            f.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        std::ranges::sort(nums);
        dfs(nums, 0, target, 0);
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    std::vector<std::vector<int>> res = sol.combinationSum2(nums, target);
    for(std::vector<int> const &result: res) {
        std::ranges::copy(result, std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }



    return 0;
}
