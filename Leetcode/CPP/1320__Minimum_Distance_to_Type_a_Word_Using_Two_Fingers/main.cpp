



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    int dp[27][27][301];
public:
    int distance(int const &xy, int const &hk) {
        int const x = xy / 6, y = xy % 6;
        int const h = hk / 6, k = hk % 6;
        return std::abs(x - h) + std::abs(y - k);
    }

    int dfs(std::string const &word, int i, int j, int k) {
        int const n = word.length();
        if(k >= n) { return 0; }
        if(dp[i][j][k] != -1) { return dp[i][j][k]; }
        int const w = word[k] - 'A';
        int const left = i != 26 ? distance(i, w) : 0, right = j != 26 ? distance(j, w) : 0;
        return dp[i][j][k] = std::min(left + dfs(word, w, j, k+1), right + dfs(word, i, w, k+1));

    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return dfs(word, 26, 26, 0);
    }
};

int main() {
    Solution sol;
    std::string word = "CAKE"; // output is 3    
    std::fprintf(stdout, "%d\n", sol.minimumDistance(word));


    return 0;
}
