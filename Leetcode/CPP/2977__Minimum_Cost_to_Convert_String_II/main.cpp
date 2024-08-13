



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    inline static constexpr int const inf = INT_MAX/2;
public:
    using element = std::pair<int, std::string>; // cost, index
public:
    std::unordered_map<std::string, std::vector<element>> g;
    std::unordered_map<std::string, std::vector<int>> source_index;
    std::unordered_map<std::string, std::vector<int>> target_index;
    std::priority_queue<element, std::vector<element>, std::greater<element>> t;
public:
    std::vector<std::vector<int>> dp;
public:
    void dijkstra(int index, vector<string>& original, vector<string>& changed) {
        t.push({0, original[index]});
        while(not t.empty()) {
            element const popped = t.top(); t.pop();
            int const curr = popped.first;
            std::string const node = popped.second;
            for(element const &ch_node: g[node]) {
                int const ch_cost = ch_node.first;
                std::string const ch_string = ch_node.second;
                for(int const &child: target_index[ch_string]) {
                    if(ch_cost + curr < dp[index][child]) {
                        dp[index][child] = ch_cost + curr;
                        t.push({dp[index][child], ch_string});
                    }
                }
            }
        }
    }

    long dfs(string &source, string target, int index) {
        int const n = source.length();
        while(index < n and source[index] == target[index]) { ++index; }
        if(index >= n or source == target) { return 0L; }
        long res = inf;
        for(int sz = n-1; sz >= 1; --sz) {
            std::string const s_string = source.substr(index, sz), t_string = target.substr(index, sz);
            if(source_index.count(s_string) and target_index.count(t_string)) {
                for(int const &s_index: source_index[s_string]) {
                    for(int const &t_index: target_index[t_string]) {
                        source = source.substr(0, index) + t_string + source.substr(index+sz);
                        res = std::min(res, dp[s_index][t_index] + dfs(source, target, index+1));
                    }
                }
            }
        }
        return res;
    }

    long long minimumCost(string source,
                          string target, vector<string>& original,
                                         vector<string>& changed, vector<int>& cost) {
        int const n = original.size();
        dp.resize(original.size(), std::vector<int>(changed.size(), inf));
        for(int i = 0; i < n; ++i) {
            g[original[i]].push_back({cost[i], changed[i]});
            source_index[original[i]].push_back(i);
            target_index[changed[i]].push_back(i);
        }

        for(int i = 0; i < n; ++i) {
            dijkstra(i, original, changed);
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < changed.size(); ++j) {
                if(original[i] == changed[j]) {
                    dp[i][j] = 0;
                }
            }
        }

        long res = 0L;
        int const sx = source.length();

        for(int i = 0; i < sx-1; ++i) {
            if(source[i] == target[i]) { continue; }
            int j = i;
            while(source[j] != target[j]) { ++j; }
            std::string const s = source.substr(i, j-i+1), t = target.substr(i, j-i+1);
            if(source_index.count(s) == 0 or target_index.count(t) == 0) { continue; }
            int const si = source_index[s][0], rj = target_index[t][0];
            res += dp[si][rj];            
            source = source.substr(0, i) + t + source.substr(i + s.size());
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::string source = "abcd", target = "acbe";
    std::vector<std::string> original = {"a","b","c","c","e","d"}, changed = {"b","c","b","e","b","e"};
    std::vector<int> cost = {2,5,5,1,2,20};

    std::fprintf(stdout, "%lld\n", sol.minimumCost(source, target, original, changed, cost));



    return 0;
}
