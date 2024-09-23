



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> seen;
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(std::vector<int> const &p: points) {
            seen.clear();
            for(std::vector<int> const &q: points) {
                seen[(p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1])] += 1;
            }
            for(std::pair<int const, int> const &node: seen) {
                res += (node.second * (node.second - 1));
            }
        }

        return res;
    }
};


int main() {
    std::vector<std::vector<int>> points = {{0,0},{1,0},{2,0}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.numberOfBoomerangs(points));


    return  0;
}
