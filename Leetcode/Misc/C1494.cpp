



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
	int const target = (1 << (n+1)) - 2;
        int g[n+1];
	memset(g, 0, sizeof(g));
	for(std::vector<int> const &relation: relations) {
	    g[relation[1]] |= (1 << relation[0]);
	}
	std::queue<std::pair<int, int>> t;
	std::unordered_set<int> visited;
	t.push({0,0});
	while(not t.empty()) {
	    std::pair<int, int> const p = t.front(); t.pop();
	    int const curr = p.first, sems = p.second;
	    if(curr == target) { return sems; }
	    if(not visited.count(curr)) {
		visited.insert(curr);
		int nxt = 0;
		for(int i = 1; i <= n; ++i) {
		    if((g[i] & curr) == g[i]) {
			nxt |= (1 << i);
		    }
		}
		if(__builtin_popcount(nxt) <= k) {
		    if(not visited.count(nxt | curr)) {
			t.push({nxt | curr, sems + 1});
		    }
		} else {
		    int temp = nxt;
		    while(temp) {
			if(__builtin_popcount(temp) == k and (not visited.count(temp | curr))) {
			    t.push({temp | curr, sems + 1});
			}
			temp = (temp - 1) & nxt;
		    }
		}
	    }
	}
	return 0;
    }
};

int main() {
    int n = 4;
    std::vector<std::vector<int>> relations = {{2,1},{3,1},{1,4}};
    int k = 2;


    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minNumberOfSemesters(n, relations, k));
}
