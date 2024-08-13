



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::vector<std::vector<int>> g;
    std::unordered_map<long long, int> freq;
public:
    int res = 0, ans = 0;
public:
    void rx(int const &node, int const &parent, int const &n) {
        for(int const &child: g[node]) {
            if(child != parent) {
                res += freq[node * 1LL * (n + 1) + 0LL + child];
                rx(child, node, n);
            }
        }
    }

    void fx(int const &node, int const &parent, int const &n, int const &k) {
        ans = ans + (res >= k);
        for(int const &child: g[node]) {
            if(child != parent) {
                int const a = freq[node * 1LL * (n+1) + 0LL + child], b = freq[child * 1LL * (n+1) + 0LL + node];
                res -= a;
                res += b;
                fx(child, node, n, k);
                res += a;
                res -= b;
            }
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int const n = edges.size();
        g.resize(n + 1);
        for(std::vector<int> const &edge: edges) {
            int const u = edge[0], v = edge[1];
            g[u].push_back(v); // consistent direct access to array elments throws TLE
            g[v].push_back(u);
        }

        for(std::vector<int> const &guess: guesses) {
            int const parent = guess[0], child = guess[1];
            freq[parent * 1LL * (n+1) + 0LL + child] += 1;
        }

        rx(0, -1, n);
        fx(0, -1, n, k);

        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> edges = {{0,1},{1,2},{1,3},{4,2}}, guesses = {{1,3},{0,1},{1,0},{2,4}};
    int k = 3;
    std::fprintf(stdout, "%d\n", sol.rootCount(edges, guesses, k));


    return 0;
}
