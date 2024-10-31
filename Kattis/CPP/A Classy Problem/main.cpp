



#include <bits/stdc++.h>

std::unordered_map<std::string, std::string> g = {
    {"lower",  "1"},
    {"middle", "2"},
    {"upper",  "3"}
};

std::string parse(std::string const &input_string) {
    std::istringstream ss(input_string);
    std::string res = "";
    std::string station;
    while(std::getline(ss, station, '-')) {
        res += g[station];
    }

    return res;
}

std::pair<std::string, std::string> decide(std::string const input) {
    std::istringstream ss(input);
    std::string line;
    std::string class_act;
    std::string class_string = "";
	std::string name = "";
    bool action = false;
    while(std::getline(ss, line, ':')) {
		// std::fprintf(stdout, "line [%s]\n", line.c_str());
        if(not action) { name = line; action = true; continue; }
        if(action) { class_act = line; }
        std::stringstream rs(class_act);
        while(class_string.empty() and std::getline(rs, class_act, ' ')) {
            if(action) { action = false; continue; }
            class_string = std::string(class_act.begin(), class_act.end());
            // std::fprintf(stdout, "class string: %s\n", class_string.c_str());
			action = true;
        }
    }
	// std::fprintf(stdout, "name is (%s) and class name is (%s)\n", name.c_str(), class_string.c_str());
    return std::make_pair(parse(class_string), name);
}

int main() {
	int t = 0, n = 0;
	std::string line;
	std::cin >> t;
	while(t--) {
		std::vector<std::pair<std::string, std::string>> hierarchies;
		std::cin >> n;
		line.clear();
		while(0 <= n--) {
			std::getline(std::cin, line);
			hierarchies.push_back(decide(line));
		}
		std::ranges::sort(hierarchies, [&](std::pair<std::string, std::string> const &a, std::pair<std::string, std::string> const &b){
			return a.first == b.first ? a.second < b.second : a.first > b.first;
		});
		for(std::size_t i = 0; i < hierarchies.size(); ++i) {
			std::pair<std::string, std::string> const elem = hierarchies[i];
			(i == hierarchies.size() - 1) ?
				std::cout << elem.second : std::cout << elem.second << '\n';
		}
		std::cout << std::string(30, '=') << '\n';
		hierarchies.clear();
	}



    return 0;
}
