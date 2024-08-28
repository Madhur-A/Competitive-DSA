



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int timings[1001][1001];
    int nvalues[1001];
public:
    std::unordered_map<int, std::vector<int>> g;
public:
    int ans = INT_MIN;
public:
    void rx(int const &source, std::vector<bool> &visited, int const &quality, int const &time_rem) {
        if(source == 0) { ans = std::max(ans, quality); }
        for(int const &child: g[source]) {
            int const travel_time = time_rem - timings[source][child];
            if(travel_time >= 0) {
                if(not visited[child]) {
                    visited[child] = true;
                    rx(child, visited, quality + nvalues[child], travel_time);
                    visited[child] = false;
                } else {
                    rx(child, visited, quality, travel_time);
                }
            }
        }
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        memset(timings, 0, sizeof(timings));
        memset(nvalues, 0, sizeof(nvalues));
        int i = 0;
        for(int const &value: values) { nvalues[i++] = value; }
        for(std::vector<int> const &edge: edges) {
            int const u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
            timings[u][v] = edge[2];
            timings[v][u] = edge[2];
        }
        std::vector<bool> visited(values.size());
        visited[0] = true;
        rx(0, visited, values[0], maxTime);
        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> edges = {{0,1,10},{1,2,15},{0,3,10}};
    std::vector<int> values = {0,32,10,43};
    int maxTime = 49;
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.maximalPathQuality(values, edges, maxTime));


    return 0;
}
