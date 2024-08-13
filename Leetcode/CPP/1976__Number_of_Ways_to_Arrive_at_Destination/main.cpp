



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    inline static constexpr long const mod = 1'000'000'007;
public:
    using element = std::pair<long long, long long>;
public:
    std::vector<std::vector<element>> g;
    std::priority_queue<element, std::vector<element>, std::greater<element>> t;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        g.resize(n);
        for(std::vector<int> const &road: roads) {
            g[road[0]].push_back({road[1], road[2]});
            g[road[1]].push_back({road[0], road[2]});
        }
        std::vector<long long> distances(n, LLONG_MAX), ways(n, 0LL);
        std::vector<bool> visited(n);
        distances[0] = 0LL; ways[0] = 1LL;
        t.push({0LL, 0LL});
        while(not t.empty()) {
            element const p = t.top(); t.pop();
            long long const curr = p.first, node = p.second;
            if(not visited[node]) {
                visited[node] = true;
                for(element const &children: g[node]) {
                    int const child = children.first, cost = children.second;
                    if((curr + 0LL + cost) < distances[child]) {
                        distances[child] = curr + 0LL + cost;
                        ways[child] = ways[node];
                        t.push({distances[child], child});
                        continue;
                    }
                    if((curr + 0LL + cost) == distances[child]) {
                        ways[child] = (ways[child] + 0LL + ways[node]) % mod;
                    }
                }
            }
        }
        return ways[n-1];
    }
};

int main() {
    Solution sol;
    int n = 7;
    std::vector<std::vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    std::fprintf(stdout, "%d\n", sol.countPaths(n, roads));

    return 0;
}
