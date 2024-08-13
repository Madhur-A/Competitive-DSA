



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::vector<std::vector<int>> g;
    std::vector<std::vector<int>> ans;
    std::vector<bool> visited;
    std::vector<int> curr_min, global_min;
public:
    void dfs(int source, int parent = -1, int minutes = 0) {
        curr_min[source] = global_min[source] = minutes;
        visited[source] = true;
        for(int const &child: g[source]) {
            if(not visited[child]) {
                dfs(child, source, minutes+1);
                global_min[source] = std::min(global_min[source], global_min[child]);
                if(global_min[child] > curr_min[source]) { ans.push_back({source, child}); }
            }
            global_min[source] = (child != parent) ? std::min(global_min[source], global_min[child]) : global_min[source];
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        g.resize(n); visited.resize(n); curr_min.resize(n, -1); global_min.resize(n, -1);
        for(std::vector<int> const &connection: connections) {
            g[connection[0]].push_back(connection[1]);
            g[connection[1]].push_back(connection[0]);
        }

        dfs(0);

        return ans;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> res = sol.criticalConnections(n, connections);
    std::ranges::for_each(res, [&](std::vector<int> const &e) {
        std::ranges::copy(e, std::ostream_iterator<int>(std::cout, " ")); std::putc('\n', stdout);
    });



    return 0;
}
