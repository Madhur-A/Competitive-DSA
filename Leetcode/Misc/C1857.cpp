



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    std::unordered_map<int, std::vector<int>> g;
    std::deque<int> t;
    std::vector<int> degs;
    std::vector<std::vector<int>> freq;
public:    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int const n = colors.size();
	degs.resize(n);
	freq.resize(n, std::vector<int>(26));
	
        for(std::vector<int> const &edge: edges) { 
            g[edge[0]].push_back(edge[1]);
	    degs[edge[1]] += 1;
        }

	for(int i = 0; i < n; ++i) {
	    if(degs[i] == 0) { t.push_back(i); }
	}
	
	int res = 0, ans = 0;	
	while(not t.empty()) { // Kahn's Algorithm
	    int const parent = t.front(); t.pop_front();
	    res += 1;
	    freq[parent][colors[parent]-'a'] += 1;
	    ans  = std::max(ans, freq[parent][colors[parent]-'a']);
	    for(int const &child: g[parent]) {
		for(int i = 0; i < 26; ++i) {
		    freq[child][i] = std::max(freq[child][i], freq[parent][i]);
		}
		degs[child] = degs[child] - 1;
		if(degs[child] == 0) {
		    t.push_back(child);
		}
	    }
	}
	return res != n ? -1 : ans;
    }
};

int main() {
    std::string colors = "abaca";
    std::vector<std::vector<int>> edges = {{0,1},{0,2},{2,3},{3,4}};

    Solution sol;
    std::fprintf(stdout, "%d\n", sol.largestPathValue(colors, edges));


    return 0;
}
