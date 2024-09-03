



class Solution {
public:
    std::vector<int> given = std::vector<int>(10, 0);
    int res = INT_MAX;
public:
    int distributeCookies(vector<int>& nums, int k, int index = 0) {
        int const n = nums.size();
        [&]() {
            if(index == n) { res = std::min(res, std::ranges::max(given)); return; }
            for(int i = 0; i < k; ++i) {
                given[i] += nums[index];
                this->distributeCookies(nums, k, index + 1);
                given[i] -= nums[index];
            }
        }(); // warning! this lambda is a lit-fuse (not to be imitated, LOL)!

        return res;
    }
};
