



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> freq;
    std::vector<int> next;
    std::vector<long long> dp;
public:
    long long dfs(vector<int>& power, int index) {
        int const n = power.size();
        if(index < n) {
            if(dp[index]) { return dp[index]; }
            int const p = power[index], f = freq[power[index]];
            long long skip = dfs(power, index + f);
            long long pick = p * 1LL * f + dfs(power, next[index]);
            return dp[index] = std::max(pick, skip);
        }
        return 0;
    }

    int find_right(vector<int>& power, int target) {
        int left = 0, right = power.size(), mid = 0;
        while(left < right) {
            mid = left + ((right - left) >> 1);
            if(power[mid] > target) {
                right = mid;
            } else {
                left  = mid + 1;
            }
        }
        return left;
    }

    long long maximumTotalDamage(vector<int>& power) {
        int const n = power.size();
        std::ranges::sort(power);
        next.resize(n); dp.resize(n, 0LL);
        for(int i = 0; i < n; ++i) {
            freq[power[i]] += 1;
            next[i] = find_right(power, power[i]+2);
        }
        return dfs(power, 0);
    }
};

int main() {
    std::vector<int> power = {1,1,3,4};
    Solution sol;
    std::fprintf(stdout, "%lld\n", sol.maximumTotalDamage(power));


    return 0;
}
