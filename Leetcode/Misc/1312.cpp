




#include <bits/stdc++.h>

using std::string;

class Solution {
public:
    int dp[501][501];
public:
    int rx(std::string const &s, int const &left, int const &right) {
        if(left < right) {
            if(dp[left][right] != -1) { return dp[left][right]; }
            int res = 0;
            if(s[left] == s[right]) {
                res = rx(s, left+1, right-1);
            } else {
                res = 1 + std::min(rx(s, left, right-1), rx(s, left+1, right));
            }
            return dp[left][right] = res;
        }
        return 0;
    }
    
    int minInsertions(string s) {
        int const n = s.length();
        memset(dp, -1, sizeof(dp));
        return rx(s, 0, n-1);
    }
};

int main() {
    std::string s = "zzazz";
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minInsertions(s));


    return 0;
}
