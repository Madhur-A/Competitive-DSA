



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        int const n = s.size();
        std::vector<int> dp(n+1);

        for(int i = 1; i < n+1; ++i) {
            dp[i] = dp[i-1] + 1;
            for(std::string const &word: dictionary) {
                int const m = word.length();
                if(i >= m) {
                    bool flag = true;
                    for(int j = i-m; j < i; ++j) {
                        if(s[j] != word[j-i+m]) {
                            flag = false;
                            break;
                        }
                    }
                    dp[i] = flag ? std::min(dp[i], dp[i-m]) : dp[i];
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    std::string s = "leetscode";
    std::vector<std::string> dictionary = {"leet","code","leetcode"};
    std::fprintf(stdout, "%d\n", sol.minExtraChar(s, dictionary));


    return 0;
}
