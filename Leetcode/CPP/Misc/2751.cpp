



#include <bits/stdc++.h>
#include <ranges>

using std::vector;
using std::string;

class Solution {
public:
    using element = std::tuple<int, int, int, int>;
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
	    int const n = positions.size();
	    std::vector<element> bots, stack;

	    for(int i = 0; i < n; ++i) {
	        bots.push_back({i, positions[i], healths[i], directions[i]});
	    }
	
	    std::ranges::sort(bots, [](element const &a, element const &b) { return std::get<1>(a) < std::get<1>(b); });
	    for(element &e: bots) {	    
	        if(std::get<3>(e) == 'R') { stack.push_back(e); continue;  }
	        while(not stack.empty() and std::get<3>(stack.back()) == 'R' and std::get<2>(e) > 0) {
		        if(std::get<2>(stack.back()) == std::get<2>(e)) {
		            stack.pop_back();
		            std::get<2>(e) = 0;
		        } else if(std::get<2>(stack.back()) < std::get<2>(e)) {
		            stack.pop_back();
		            std::get<2>(e) -= 1;
		        } else {
		            std::get<2>(stack.back()) -= 1;
		            std::get<2>(e) = 0;
		        }
	        }
	        if(std::get<2>(e) > 0) { stack.push_back(e); }
	    }
	
	    std::ranges::sort(stack, [](element const &a, element const& b) { return std::get<0>(a) < std::get<0>(b); });
	    std::vector<int> ans;
	    for(element const &e: stack) { ans.push_back(std::get<2>(e)); }
	
	    return ans;
    }
};

int main() {
    //  positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
    std::vector<int> positions = {1,2,5,6}; //{3,5,2,6};
    std::vector<int> healths = {10,10,11,11}; //{10,10,15,12};
    std::string directions = "RLRL";
    Solution sol;
    std::vector<int> ans = sol.survivedRobotsHealths(positions, healths, directions);
    std::ranges::copy(ans, std::ostream_iterator<int>(std::cout, " "));
    std::putc('\n', stdout);


    return 0;
}

