



#include <bits/stdc++.h>

class Solution {
public:    
    int dp[11][21][50][2][2];
public:
    int solve(std::string const &num, int n, int diff, int sum, int k, bool leading, bool tight) {
        if(n == 0) { return (diff == 0) and (sum == k); }
        
        if(dp[n][10+diff][sum][leading][tight] != -1) return dp[n][10+diff][sum][leading][tight];
        
        int ans = 0;
        int ub = tight ? num[num.size()-n] - '0' : 9;
        
        for(int digit = 0; digit <= ub; ++digit) {
            if(digit == 0 and leading) {
                ans += solve(num, n-1, diff, (sum%k)+k, k, 1, 0);
            } else {
                int val = 1;
                for(int i=0; i < n-1; ++i) { val *= 10; }
                
                if(not (digit & 1)) {
                    ans += solve(num, n-1, diff+1, ((sum+(digit*val)) % k) + k, k, 0, (tight & (ub == digit)));
                } else {
                    ans += solve(num, n-1, diff-1, ((sum+(digit*val)) % k) + k, k, 0, (tight & (ub == digit)));
                }
            }
        }
        
        return dp[n][10+diff][sum][leading][tight] = ans;
    }
    
    int numberOfBeautifulIntegers(int low, int high, int k) {
        std::string l = std::to_string(low-1), r = std::to_string(high);
        
        memset(dp, -1, sizeof(dp));
        int a = solve(l, l.size(), 0, 0, k, 1, 1);
        memset(dp, -1, sizeof(dp));
        int b = solve(r, r.size(), 0, 0, k, 1, 1);
        
        return b-a;      
    }
};

int main() {
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.numberOfBeautifulIntegers(10, 20, 3));


    return 0;
}

