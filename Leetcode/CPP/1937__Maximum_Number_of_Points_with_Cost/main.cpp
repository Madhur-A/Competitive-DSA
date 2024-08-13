



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::vector<long> curr;
    std::vector<long> prev;
public:
    long long maxPoints(std::vector<std::vector<int>>& points) {
        int const c = points[0].size();
        long left = 0, right = 0;
        prev.resize(c, 0L);

        for(std::vector<int> const &row: points) {
            curr.assign(c, 0L);
            left  = LONG_MIN;
            right = LONG_MIN;
            for(int j = 0; j < c; ++j)  {
                left  = std::max(left, prev[j] + 0L + j);
                curr[j] = std::max(curr[j], row[j] + left - j);
            }
            for(int j = c-1; j >= 0; --j) {
                right = std::max(right, prev[j] + 0L - j);
                curr[j] = std::max(curr[j], row[j] + right + j);
            }
            prev = curr;
        }

        return std::ranges::max(prev);
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> points = {{1,2,3},{1,5,1},{3,1,1}};
    std::fprintf(stdout, "%lld\n", sol.maxPoints(points));


    return 0;
}
