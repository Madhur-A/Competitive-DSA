



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    int tags[26];
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int const n = points.size();
        int max_possible = INT_MAX;
        memset(tags, 0x7F, sizeof(tags));
        for(int i = 0; i < n; ++i) {
            int const z = std::max(std::abs(points[i][0]), std::abs(points[i][1]));
            int const c = s[i] - 'a';
            if(tags[c] == INT_MAX) { // first seen
                tags[c] = z;
            } else if(tags[c] > z) {
                max_possible = std::min(max_possible, tags[c]); // max possible length of square
                tags[c] = z;
            } else {
                max_possible = std::min(max_possible, z);
            }
        }

        return std::ranges::count_if(tags, [&](int const &tag) { return tag < max_possible; } );
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> points = {{2,2},{-1,-2},{-4,4},{-3,1},{3,-3}};
    std::string s = "abdca";
    std::fprintf(stdout, "%d\n", sol.maxPointsInsideSquare(points, s));

    return 0;
}
