




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using element = std::pair<double, int>;
public:
    std::vector<std::vector<element>> g;
    std::priority_queue<element> t;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        g.resize(n);
        int i = 0;
        for(std::vector<int> const &edge: edges) {
            g[edge[0]].push_back({succProb[i], edge[1]});
            g[edge[1]].push_back({succProb[i], edge[0]});
            i += 1;
        }
        std::vector<double> total(n, 0.0);
        total[start_node] = 1.0;
        t.push({1.0, start_node});
        while(not t.empty()) {
            element const p = t.top(); t.pop();
            double const prob = p.first;
            int const node = p.second;
            if(node == end_node) { return prob; }
            for(element const &children: g[node]) {
                double const next_prob = children.first * prob;
                if(total[children.second] < next_prob) {
                    total[children.second] = next_prob;
                    t.push({next_prob, children.second});
                }
            }
        }
        return total[end_node];
    }
};

int main() {
    Solution sol;
    int n = 3;
    std::vector<std::vector<int>> edges = {{0,1},{1,2},{0,2}};
    std::vector<double> succProb = {0.5,0.5,0.2};
    int start = 0, end = 2;

    std::fprintf(stdout, "%f\n", sol.maxProbability(n, edges, succProb, start, end));


    return 0;
}

