




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int dfs(vector<int>& nums) {
        int const   n = nums.size();
        int const inf = 100000;
        std::vector<int> dp(n, inf);

        std::function<int(int)> rx = [&](int i) {
            if(i        > n-2) { return     0; }
            if(nums[i] ==   0) { return dp[i]; }
            if(dp[i]   != inf) { return dp[i]; }

            for(int j = i + nums[i]; j > i; --j) {
                dp[i] = std::min(dp[i], 1 + rx(j));
            }

            return dp[i];
        };

        return rx(0);
    }

    int bfs(vector<int>& nums) {
        int const n = nums.size();
        std::vector<bool> visited(n);
        std::queue<int> t;
        t.push(0);
        int res = 0;

        while(not t.empty()) {
            res += 1;
            int const z = t.size();
            for(int l = 0; l < z; ++l) {
                int const i = t.front(); t.pop();
                if(i == n-1) { return res - 1; }
                if(not visited[i]) {
                    visited[i] = true;
                    for(int k = 0; k <= nums[i] and i+k < n; ++k) {
                        if(not visited[i + k]) {
                            t.push(i + k);
                        }
                    }
                }
            }
        }

        return -1; // by problem constraints control never reaches here
    }

    int canonical(vector<int>& nums) {
        int const n = nums.size();
        int res = 0, max_so_far = 0, index = 0;
        for(int i = 0; i < n-1; ++i) {
            max_so_far = std::max(max_so_far, i + nums[i]);
            if(i == index) {
                index = max_so_far;
                res += 1;
            }
        }
        return res;
    }

    int jump(vector<int>& nums) {
//         return dfs(nums);
//         return bfs(nums);
        return canonical(nums);
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {2,3,1,1,4};
    std::fprintf(stdout, "%d\n", sol.jump(nums));


    return 0;
}

