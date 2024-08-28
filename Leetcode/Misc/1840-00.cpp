



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using element = std::pair<int, int>;
public:
    std::vector<std::pair<int, int>> permissible;
    std::vector<std::vector<bool>> valid;
    std::queue<element> t;
public:
    int maxBuilding(int n, vector<vector<int>>& banned) {
	valid.resize(n+1, std::vector<bool>(n+1, true));
	permissible.push_back({0, 0});
	permissible.push_back({1, 0});
	for(std::vector<int> const &edge: banned) {
	    permissible.push_back({edge[0], edge[1]});
	}
	permissible.push_back({n, n-1});
	std::ranges::sort(permissible);

	for(unsigned long i = 1; i < permissible.size(); ++i) {
	    permissible[i].second = std::min(permissible[i].second, permissible[i-1].second + permissible[i].first - permissible[i-1].first);
	}
	for(unsigned long i = permissible.size()-2; i >= 0; --i) {
	    permissible[i].second = std::min(permissible[i].second, permissible[i+1].second + permissible[i].first - permissible[i+1].first);
	}

	int ans = 0;
	for(unsigned long i = 1; i < permissible.size(); ++i) {
	    int const f_left = permissible[i-1].first,  f_right = permissible[i].first;
	    int const s_left = permissible[i-1].second, s_right = permissible[i].second;
	    ans = std::max(ans, std::max(s_left, s_right)  + (f_right - f_left - std::abs(s_left - s_right))/2);
	}
	
	
	// t.push({0, 0}); //index, height
	// while(not t.empty()) {
	//     element const popped = t.front(); t.pop();
	//     int const index = popped.first, height = popped.second;
	//     if(index <= n and height >= 0 and height <= permissible[index] and valid[index][height]) {
	// 	ans = std::max(ans, height);
	// 	t.push({index+1, height-1});
	// 	t.push({index+1, height+0});
	// 	t.push({index+1, height+1});
	//     }
	// }
	return ans;
    }
};

int main() {
    int n = 5;
    std::vector<std::vector<int>> restrictions = {{2,1},{4,1}};

    Solution sol;
    std::fprintf(stdout, "%d\n", sol.maxBuilding(n, restrictions));


    return 0;
}
