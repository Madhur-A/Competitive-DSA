




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    //1. BFS Using PQ
    int bfs_prioritized(std::vector<int> const &nums, int target) {
        std::priority_queue<std::pair<int, int>> t;
        std::unordered_set<int> seen;
        t.push({0, 0});
        while(not t.empty()) {
            std::pair<int, int> const p = t.top(); t.pop();
            if(p.first == target) { return p.second; }
            for(int const &num: nums) {
                if(p.first + num <= target and not seen.count(p.first + num)) {
                    t.push({p.first + num, p.second + 1});
                    seen.insert(p.first + num);
                }
            }
        }
        return -1;
    }

    //2. DP top-down
    int dfs(std::vector<int> &nums, int target) {
        int const inf = INT_MAX / 2;
        std::unordered_map<int, int> dp;
        std::ranges::reverse(nums);
        std::function<int(int)> rx = [&](int remaining) {
            if(remaining      == 0) { return 0;             }
            if(dp.count(remaining)) { return dp[remaining]; }

            int res = inf, aux = -1;
            for(int const &num: nums) {
                if(remaining >= num and num != 0) {
                    aux = rx(remaining - num);
                    if(aux != -1) {
                        res = std::min(res, 1 + aux);
                    }
                }
            }
            return dp[remaining] = (res == inf) ? -1 : res;
        };

        return rx(target);
    }

    //3. DP bottom-up
    int bottom_up(std::vector<int> const &nums, int target) {
        std::vector<int> dp(target + 1, INT_MAX);
        dp[0] = 0;
        for(int j = 1; j < target+1; ++j) {
            for(int const &num: nums) {
                if(j >= num and dp[j - num] != INT_MAX) {
                    dp[j] = std::min(dp[j], dp[j - num] + 1);
                }
            }
        }
        return (dp[target] == INT_MAX) ? -1 : dp[target];
    }

    int minimumNumbers(int num, int k) {
        int const target = num;
        std::vector<int> nums;
        for(int start = k; start <= target; start += 10) {
            nums.push_back(start);
        }

        return bfs_prioritized(nums, target);
//        return bottom_up(nums, target);
//        return dfs(nums, target);
    }
};

int main() {
    Solution sol;
    int num = 58, k = 9;
    std::fprintf(stdout, "%d\n", sol.minimumNumbers(num, k));


    return 0;
}

