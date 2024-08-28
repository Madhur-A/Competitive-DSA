



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using element = std::pair<int, int>;
public:
    std::priority_queue<element, std::vector<element>, std::greater<element>> t;
    std::priority_queue<int> u;
public:    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
	int const n = profits.size();
	int count = 0, ans = w;
	for(int i = 0; i < n; ++i) {
	    t.push({capital[i], profits[i]});
	}	
	while(count < k) {
	    while(not t.empty() and t.top().first <= ans) {
		u.push(t.top().second); t.pop();
	    }
	    if(not u.empty()) {
		ans += u.top(); u.pop();
		count += 1;
		continue;
	    }
	    break; // exit as no suitable instrument found
	}
	
	return ans;
    }
};


int main() {
    int k = 2, w = 0;
    std::vector<int> profits = {1,2,3}, capital = {0,1,1};    
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.findMaximizedCapital(k, w, profits, capital));


    return 0;    
}
