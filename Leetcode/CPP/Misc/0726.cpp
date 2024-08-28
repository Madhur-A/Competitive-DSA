



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    std::map<std::string, int> rx(std::string &formula, std::string::size_type i) {
	std::map<std::string, int> freqs;
	while(i != formula.length() and formula[i] != ')') {
	    if(formula[i] == '(') {
		i += 1;
		for(std::pair<std::string const, int> const &res: rx(formula, i)) {
		    freqs[res.first] += res.second;
		}
	    } else {
		std::string::size_type begin = i++;
		while(i != formula.length() and std::islower(formula[i])) { ++i; }
		std::string name = formula.substr(begin, i-begin);
		begin = i;
		while(i != formula.length() and std::isdigit(formula[i])) { ++i; }
		std::string::size_type freq = begin == i ? 1 : std::stoi(formula.substr(begin, i - begin));
		freqs[name] = freq;
	    }
	}
	std::string::size_type begin = ++i;
	while(i != formula.length() and std::isdigit(formula[i])) { i++; }
	if(begin < i) {
	    int const mux = std::stoi(formula.substr(begin, i-begin));
	    for(std::pair<std::string const, int> &node: freqs) {
		node.second = node.second * mux;
	    }
	}
	
	return freqs;
    }
    
    string countOfAtoms(string formula) {
	// std::string::size_type const n = formula.length();
	std::map<std::string, int> g = rx(formula, 0);
	std::string ans;
	for(std::pair<std::string const, int> const &node: g) {
	    ans += node.first;
	    if(node.second > 1) { ans += std::to_string(node.second); }
	}
	return ans;
    }
};


int main() {
    std::vector<std::string> formulae = {"H2O", "Mg(OH)2", "H2MgO2"};
    Solution sol;
    for(std::string const &formula: formulae) {
	std::fprintf(stdout, "%s\n", sol.countOfAtoms(formula).c_str());
    }


    return 0;
}
