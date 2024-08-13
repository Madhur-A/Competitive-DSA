



#include <bits/stdc++.h>
#include <queue>

using std::vector;

class Solution {
public:
    using element = std::pair<int, int>;
public:
    inline static constexpr element const inf_pair = {INT_MAX, INT_MAX};
public:
    std::unordered_map<int, std::vector<int>> g;
    std::priority_queue<element, std::vector<element>, std::greater<element>> t;
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        for(std::vector<int> const &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        std::vector<int> visited(n+1);
        std::vector<element> timings(n+1, inf_pair);
        t.push({0, 1}); // duration, node
        while(not t.empty()) {
            int const z = t.size();
            for(int l = 0; l < z; ++l) {
                element const p = t.top(); t.pop();
                int const node = p.second, duration = p.first;
                visited[node] += 1;
                if(node == n and visited[node] == 2) { return duration; }
                if(visited[node] <= 2) {
                    int const   interval = duration/change;
                    int const total_time = time + ((interval & 1) ? change * (interval + 1) : duration);
                    for(int const &child: g[node]) {
                        if(visited[child] <= 2) {
                            if(timings[child].first > total_time) {
                                timings[child].second = timings[child].first;
                                timings[child].first = total_time;
                                t.push({total_time, child});
                                continue;
                            }
                            if(timings[child].second > total_time) {
                                if(timings[child].first != total_time) {
                                    timings[child].second = total_time;
                                    t.push({total_time, child});
                                }
                            }
                        }
                    }
                }
            }
        }
        return EXIT_FAILURE; // control shouldn't reach here
    }
};

int main() {
    Solution sol;
    int n = 5;
    std::vector<std::vector<int>> edges = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    int time = 3, change = 5;    
    std::fprintf(stdout, "%d\n", sol.secondMinimum(n, edges, time, change));
    
    
    return 0;
}
