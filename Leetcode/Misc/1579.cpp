



#include <bits/stdc++.h>

using std::vector;

template<typename __buffer>
struct disjoint {
public:
    using vector_tp = __buffer;
private:
    int count;
    vector_tp roots;
    vector_tp ranks;
public:
    inline constexpr disjoint(int const &n): count(n), roots(n+1), ranks(n+1, 1) {
        for(int i = 0; i < count; ++i) { roots[i] = i; }
    }
    
    inline constexpr int find(int const &i) {
        return roots[i] == i ? i : roots[i] = find(roots[i]);
    }
    
    inline constexpr bool merge(int const &i, int const &j) {
        int const pi = find(i),   pj = find(j);
        int const ri = ranks[pi], rj = ranks[pj];
        if(pi != pj) {
            if(rj < ri) {
                roots[pj]  = pi;
                ranks[pi] += ranks[pj];
            } else {
                roots[pi]  = pj;
                ranks[pj] += ranks[pi];
            }
            count = count - 1;
            return false;
        }
        return true;
    }
    
    inline constexpr int rem() const { return count; }
    
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        disjoint<std::vector<int>> alice(n+1);
	disjoint<std::vector<int>> bob(n+1);
        int ans = 0;
        for(std::vector<int> const &edge: edges) {
            int const tp = edge[0], u = edge[1], v = edge[2];
            if(tp == 3) {
                bool const a = alice.merge(u, v), b = bob.merge(u, v);
                ans += (a and b);
            }
        }
        for(std::vector<int> const &edge: edges) {
            int const tp = edge[0], u = edge[1], v = edge[2];
            if(tp == 1) { ans += alice.merge(u, v); }
            if(tp == 2) { ans += bob.merge(u, v); }
        }

        return (alice.rem() == 2 and bob.rem() == 2) ? ans : -1;
    }
};

int main() {
    int const n = 4;
    std::vector<std::vector<int>> edges = {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.maxNumEdgesToRemove(n, edges));


    return 0;
}
