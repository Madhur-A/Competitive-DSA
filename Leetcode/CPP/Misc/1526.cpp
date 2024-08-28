



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int const n = target.size();
        int ans = target[0];
        for(int i = 1; i < n; ++i) {
            ans += ((target[i] - target[i-1]) * (target[i] > target[i-1]));
        }
        return ans;
    }
};

int main() {
    std::vector<int> target = {1,2,3,2,1};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minNumberOperations(target));


    return 0;
}
