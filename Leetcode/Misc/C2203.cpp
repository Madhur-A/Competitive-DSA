



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using element = std::pair<long, int>; // distance, node
public:
    inline static constexpr long const inf = 1000000000000;
public:
    std::priority_queue<element, std::vector<element>, std::greater<element>> t;
    std::vector<std::vector<element>> g, r;
public:
    std::vector<long> dijkastra(int const &n, int const &source, bool const &reverse=false) {
        std::vector<long> res(n, inf);
        t.push({0, source});
        res[source] = 0;
        while(not t.empty()) {
            element const p = t.top(); t.pop();
            long const distance = p.first;
            int const node = p.second;
            if(distance <= res[node]) {
                std::vector<element> const children = (reverse) ? r[node] : g[node];
                for(element const &child: children) { // child: weight, node
                    if(res[child.second] > res[node] + child.first) {
                        res[child.second] = res[node] + child.first;
                        t.push({res[child.second], child.second});
                    }
                }
            }
        }
        return res;
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
	    g.resize(n); r.resize(n);
        for(std::vector<int> const &edge: edges) {
	        int const u = edge[0], v = edge[1], weight = edge[2];
	        g[u].push_back({weight, v});
	        r[v].push_back({weight, u});
	    }
	    std::vector<long> const sx_one = dijkastra(n, src1);
	    std::vector<long> const sx_two = dijkastra(n, src2);
	    std::vector<long> const rx_one = dijkastra(n, dest, 1);

	    long ans = -1;

	    for(int i = 0; i < n; ++i) {
	        if(sx_one[i] != inf and sx_two[i] != inf and rx_one[i] != inf) {
		        long const res = sx_one[i] + sx_two[i] + rx_one[i];
		        if(ans == -1 or res < ans) { ans = res; }
	        }
	    }
        
	    return ans;
    }
};

int main() {
    Solution sol;
    int n = 6, src1 = 0, src2 = 1, dest = 5;
    std::vector<std::vector<int>> edges = {{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}};
    std::fprintf(stdout, "%lld\n", sol.minimumWeight(n, edges, src1, src2, dest));

    return 0;
}
