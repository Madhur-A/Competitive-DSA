



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::vector<std::vector<int>> g;
    std::vector<int> past_lengths;
public:
    int ans = INT_MAX;
public:
    void dfs(int node, int parent, int length) {
        past_lengths[node] = length;
        length += 1;
	for(int const &child: g[node]) {
            if(child != parent and past_lengths[child] > length) {
                dfs(child, node, length);
            }
            int const diff = length - past_lengths[child];
            ans = (diff > 1) and (child != parent) ? std::min(ans, diff) : ans;
	    if(ans == 3) { return; }
	}
    }
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        past_lengths.resize(n, INT_MAX); 
        g.resize(n);
        
        for(std::vector<int> const &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; ++i) {
            if(past_lengths[i] == INT_MAX) { dfs(i, -1, 0); }
            if(ans == 3) { return ans; }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    int n = 7;
    std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}};
    Solution sol;

    std::fprintf(stdout, "%d\n", sol.findShortestCycle(n, edges));

    return 0;
}
