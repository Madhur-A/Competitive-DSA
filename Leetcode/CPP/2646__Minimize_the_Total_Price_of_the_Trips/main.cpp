



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using element = std::pair<int, int>;
public:
    std::vector<std::vector<int>> g;
    std::vector<int> freq;
public:
    bool rx(int node, int parent, int last) {
        freq[node] += 1;
        if(node == last) { return true; }
        for(int const &child: g[node]) {
            if(child != parent and rx(child, node, last)) {
                return true;
            }
        }
        freq[node] -= 1;
        return false;
    }

    element fx(int node, int parent, vector<int>& prices) {
        int f = freq[node] * prices[node];
        int s = f / 2;
        for(int const &child: g[node]) {
            if(child != parent) {
                element const res = fx(child, node, prices);
                f += std::min(res.first, res.second);
                s += res.first;
            }
        }
        return std::make_pair(f, s);
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        g.resize(n); freq.resize(n);
        for(std::vector<int> const &edge: edges) {            
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        for(std::vector<int> const &trip: trips) { rx(trip[0], -1, trip[1]); }
        element const res = fx(0, -1, price);
        return std::min(res.first, res.second);
    }
};

int main() {
    int n = 4;
    std::vector<std::vector<int>> edges = {{0,1},{1,2},{1,3}}, trips = {{0,3},{2,1},{2,3}};
    std::vector<int> price = {2,2,10,6};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minimumTotalPrice(n, edges, price, trips));




    return 0;
}
