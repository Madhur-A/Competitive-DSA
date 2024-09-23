



#include <bits/stdc++.h>

using std::string;

class Solution {
public:
    std::unordered_map<int, long> dp;
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(s1 == s2) { return n1 >= n2; }
        int const m = s2.size(), c = std::max(n1 * s1.size(), n2 * s2.size()) + 1;
        for(int i = 0, reps = 0, j = 0; i < m; ++i, reps = 0) {
            j = i;
            for(char const &c: s1) {
				j += (c == s2[j]);
				reps += (j == m);
				j  = (j == m) ? 0 : j;
            }
            dp[i] = reps * 1L * c + j;
        }

        int total = 0, next_index = 0;
        for(int i = 0; i < n1; ++i) {
			total += dp[next_index] / c;
            next_index = dp[next_index] % c;
        }

        return total / n2;
    }
};

int main() {
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.getMaxRepetitions("aaa", 3, "aa", 1));


    return 0;
}
