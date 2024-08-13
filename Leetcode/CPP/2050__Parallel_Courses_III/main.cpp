



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::unordered_map<int, std::vector<int>> g;
    std::unordered_map<int, int> past;
    std::queue<int> t;
    int ans = 0;
public:
    int rx(int node, vector<int>& durations) {
        if(past.count(node)) { return past[node]; }
        int res = durations[node];
        for(int const &child: g[node]) {
            res = std::max(res, durations[node] + rx(child, durations));
        }
        past[node] = res;
        ans = std::max(ans, past[node]);
        return past[node];
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int const sz = relations.size();
        if(sz == 0) { return std::ranges::max(time); }

        std::vector<int> durations = {0};
        durations.insert(durations.end(), time.begin(), time.end());

        std::vector<int> h(n+1, 0);
        for(std::vector<int> const &relation: relations) {
            g[relation[0]].push_back(relation[1]);
            h[relation[1]] += 1;
        }

        std::vector<int> max_duration(n+1);
        for(int i = 1; i < n+1; ++i) {
            if(h[i] == 0) {
                t.push(i);
                max_duration[i] = durations[i];
            }
        }

        while(not t.empty()) {
            int const p = t.front(); t.pop();
            for(int const &child: g[p]) {
                max_duration[child] = std::max(max_duration[child], max_duration[p]+durations[child]);
                h[child] = h[child] - 1;
                if(h[child] == 0) {
                    t.push(child);
                }
            }
        }

        return std::ranges::max(max_duration);
    }
};


int main() {
    int n = 7;
    std::vector<std::vector<int>> relations = {{2,1},{3,1},{4,1},{4,2},{5,2},{6,2},{7,6}};
    std::vector<int> time = {0,1,2,3,4,5,6,7};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minimumTime(n, relations, time));



    return 0;
}
