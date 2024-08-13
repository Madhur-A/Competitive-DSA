



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    std::vector<int> z;
public:
    long long sumScores(string s) {
        int const n = s.length();
        z.resize(n+1);
        int left = 0, right = 0;
        long res = n;
        for(int i = 1; i < n; ++i) {
            z[i] = (i <= right) ? std::min(right-i+1, z[i-left]) : z[i];
            while(i+z[i] < n and s[z[i]] == s[i + z[i]]) { z[i] += 1; }
            if(i+z[i]-1 > right) {
                left  = i;
                right = i + z[i] - 1;
            }
            res += z[i];
        }

        return res;
    }
};

int main() {
    std::string s = "babab";
    Solution sol;
    std::fprintf(stdout, "%lld\n", sol.sumScores(s));


    return 0;
}
