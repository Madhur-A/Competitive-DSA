



#include <bits/stdc++.h>

using std::string;

class Solution {
public:
    std::unordered_map<int, std::pair<int, int>> dp;
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int m = s2.size();
        for(int i = 0, reps = 0, j = 0; i < m; ++i) {
            j = i;
            for(char const &c: s1) {
                if(c == s2[j]) { j += 1; }
                if(j == m) { reps += 1; j = 0; }
            }
            dp[i] = std::make_pair(reps, j);
            reps = 0;
        }

        int total = 0, next_index = 0;
        for(int i = 0; i < n1; ++i) {
            std::pair<int, int> const e = dp[next_index];
            next_index = e.second;
            total += e.first;
        }

        return total / n2;
    }
};

int main() {
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.getMaxRepetitions("aaa", 3, "aa", 1));


    return 0;
}
