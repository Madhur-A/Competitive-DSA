



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> freq;
    std::vector<std::pair<int, int>> f;
public:
    void rx(int index, int n, int prev, int &ans) {
        if(index == n) { ans += 1; return; }
        for(std::size_t i = 0; i < f.size(); i++) {
            if(f[i].second) {
                int const curr = f[i].first;
                if(index == 0) {
                    f[i].second -= 1;
                    rx(index + 1, n, curr, ans);
                    f[i].second += 1;
                } else {
                    int const sum = curr + prev;
                    int const sqr = std::sqrt(sum);
                    if(sqr * sqr == sum) {
                        f[i].second -= 1;
                        rx(index + 1, n, curr, ans);
                        f[i].second += 1;
                    }
                }
            }
        }
    }

    int numSquarefulPerms(std::vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        for(int const &num: nums) { freq[num] += 1; }
        f.insert(f.end(), freq.begin(), freq.end());

        int ans = 0;
        rx(0, n, -1, ans);

        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1,1,8,1,8}; //{1,17,8};
    std::fprintf(stdout, "%d\n", sol.numSquarefulPerms(nums));


    return 0;
}
