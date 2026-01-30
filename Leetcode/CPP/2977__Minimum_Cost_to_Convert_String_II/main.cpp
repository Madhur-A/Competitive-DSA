



#include <array>
#include <vector>
#include <string>
#include <cstdio>
#include <climits>

using std::vector;
using std::string;

struct trie_node {
public:
    std::array<trie_node*, 26> children;
    int node_idx = -1;
public:
    inline trie_node() {
        children.fill(nullptr);
    }
};

class Solution {
public:
    static constexpr long long inf = LLONG_MAX >> 1;
public:
    trie_node* root = new trie_node();
    int next_idx = 0;
public:
    std::vector<std::vector<long long>> cost_graph;
    std::vector<long long> seen;
    std::string source_str;
    std::string target_str;
public:
    inline int insert_into_trie(const std::string& word) {
        trie_node* curr = root;
        for (char const& c: word) {
            int const idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new trie_node();
            }
            curr = curr->children[idx];
        }
        if (curr->node_idx < 0) {
            curr->node_idx = next_idx++; //!!!
        }

        return curr->node_idx;
    }

    inline long long dfs(int const& pos) {
        int const n = source_str.length();
        if (pos >= n) { return 0; }
        if (seen[pos] != -1) { return seen[pos]; }

        long long min_cost = inf;
        if (source_str[pos] == target_str[pos]) {
            min_cost = dfs(pos + 1);
        }

        trie_node* src_node = root;
        trie_node* tgt_node = root;

        for (int end = pos; end < n; ++end) {
            src_node = src_node->children[source_str[end] - 'a'];
            tgt_node = tgt_node->children[target_str[end] - 'a'];

            if (src_node == nullptr or tgt_node == nullptr) { break; }
            if (src_node->node_idx < 0 or tgt_node->node_idx < 0) { continue; }

            long long transform_cost = cost_graph[src_node->node_idx][tgt_node->node_idx];
            if (transform_cost < inf) {
                long long candidate = transform_cost + dfs(end + 1);
                if (candidate < min_cost) { min_cost = candidate; }
            }
        }


        return seen[pos] = min_cost;
    }

public:
    long long minimumCost(std::string source,
                          std::string target,
                          std::vector<std::string>& original,
                          std::vector<std::string>& changed,
                          std::vector<int>& cost) {
        int const n = cost.size();
        cost_graph.assign(n << 1, std::vector<long long>(n << 1, inf));
        source_str = source;
        target_str = target;

        for (int i = 0; i < static_cast<int>(cost_graph.size()); ++i) {
            cost_graph[i][i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            int const from_idx = insert_into_trie(original[i]);
            int const to_idx   = insert_into_trie(changed[i]);
            cost_graph[from_idx][to_idx] = std::min(cost_graph[from_idx][to_idx],
                                                    static_cast<long long>(cost[i]));
        }

        for (int k = 0; k < next_idx; ++k) {
            for (int i = 0; i < next_idx; ++i) {
                if (cost_graph[i][k] >= inf) { continue; }
                for (int j = 0; j < next_idx; ++j) {
                    cost_graph[i][j] = std::min(cost_graph[i][j],
                                                cost_graph[i][k] + cost_graph[k][j]);
                }
            }
        }

        seen.assign(source_str.length(), -1);
        long long const res = dfs(0);


        return res >= inf ? -1 : res;
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
