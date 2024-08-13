



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, std::vector<int>> g;
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
//        int const n = scores.size();
        int ans = -1;
        for(std::vector<int> const &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        for(std::pair<int const, std::vector<int>> &node: g) {
            std::sort(node.second.begin(), node.second.end(), [&](int const &a, int const &b) {
                return scores[a] > scores[b];
            });
            while(node.second.size() > 3) {
                node.second.pop_back();
            }
        }

        for(std::vector<int> const &edge: edges) {
            int const u = edge[0], v = edge[1];
            for(int const &u_child: g[u]) {
                for(int const &v_child: g[v]) {
                    if(u_child != v_child and u_child != v and v_child != u) {
                        int const res = scores[u_child] + scores[v_child] + scores[u] + scores[v];
                        ans = std::max(ans, res);
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> scores = {5,2,9,8,4};
    std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};    
    std::fprintf(stdout, "%d\n", sol.maximumScore(scores, edges));

    return 0;
}
