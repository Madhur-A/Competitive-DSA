



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    std::vector<int> dp;
    std::unordered_set<int> seen;
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int const n = source.length(), p = pattern.length();
        seen.insert(targetIndices.begin(), targetIndices.end());
        dp.resize(p + 1, INT_MIN);

        dp[p] = 0;

        for(int i = n - 1; 0 <= i; --i) {
            for(int j = 0; j <= p; ++j) {
                dp[j] += seen.count(i);
                if(j < p and source[i] == pattern[j]) {
                    dp[j] = std::max(dp[j], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};

int main() {
	Solution sol;
	std::string source = "abbaa", pattern = "aba";
	std::vector<int> targetIndices = {0,1,2};


	return std::fprintf(stdout, "%d\n", sol.maxRemovals(source, pattern, targetIndices));
}
