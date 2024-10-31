



#include <bits/stdc++.h>

int main() {
	std::string line;
	std::unordered_set<int> seen;
	while(std::getline(std::cin, line)) {
		int sum = 0, beat = 1;
		unsigned long const n = line.length();
		bool is_sequential = true;
		seen.clear();
		for(char const &c: line) {
			sum += c - '0';
			seen.insert((c - '0' + beat) % n);
			beat += 1;
		}
		is_sequential = seen.size() == n;
		if((sum % n) != 0) {
			std::cout << line << ": invalid # of balls\n";
			continue;
		}
		if(not is_sequential) {
			std::cout << line << ": invalid pattern\n";
			continue;
		}
		std::cout << line << ": valid with " << sum / n << " balls\n";
	}

	return 0;
}
