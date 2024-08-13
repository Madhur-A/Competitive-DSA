



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> g;
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int const n = basket1.size();
        int min_cost = INT_MAX;
        for(int i = 0; i < n; ++i) {
            g[basket1[i]] += 1;
            g[basket2[i]] -= 1;
            min_cost = std::min(min_cost, std::min(basket1[i], basket2[i]));
        }
        std::vector<int> found;
        for(std::pair<int const, int> const &node: g) {
            if(node.second & 1) { return -1; }
            if(std::abs(node.second)/2 > 0) {
                std::vector<int> v(std::abs(node.second)/2, node.first);
                found.insert(found.end(), v.begin(), v.end());
            }
        }
        std::ranges::sort(found);
        long res = 0;
        for(std::size_t i = 0; i < found.size()/2; ++i) {
            res += std::min(found[i], 2*min_cost);
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> basket1 = {4,2,2,2}, basket2 = {1,4,1,2};
    std::fprintf(stdout, "%lld\n", sol.minCost(basket1, basket2));


    return 0;
}
