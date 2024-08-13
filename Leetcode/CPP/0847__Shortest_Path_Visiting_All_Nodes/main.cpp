




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using element = std::pair<int, int>;
public:
    std::queue<element> t;
    int visited[13][4097];
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int const n = graph.size(), target = (1 << n) - 1;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            t.push({i, 1 << i});
        }
        memset(visited, 0, sizeof(visited));
        while(not t.empty()) {
            ans += 1;
            int const z = t.size();
            for(int l = 0; l < z; ++l) {
                element const p = t.front(); t.pop();
                int const node = p.first, state = p.second;
                if(state == target) { return ans - 1; }
                if(not visited[node][state]) {
                    visited[node][state] = true;
                    for(int const &child: graph[node]) {
                        int const new_state = state | (1 << child);
                        if(not visited[child][new_state]) {
                            t.push({child, new_state});
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> graph = {{1,2,3},{0},{0},{0}};
    std::fprintf(stdout, "%d\n", sol.shortestPathLength(graph));

    return 0;
}
