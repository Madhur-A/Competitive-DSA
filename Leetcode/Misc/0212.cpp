



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    using direction = std::pair<int, int>;
    using   element = std::tuple<std::string, int, int, int>; // resulting_string, x, y, index
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};    
public:
    std::vector<std::string> ans;
public:
    bool bfs_check(vector<vector<char>>& board, std::string const &word, std::deque<element> &t) {
	int const r = board.size(), c = board[0].size(), limit = word.length();
	std::vector<std::vector<bool>> visited(r, std::vector<bool>(c));
	while(not t.empty()) {
	    int const z = t.size();
	    for(int l = 0; l < z; ++l) {
		element const p = t.front(); t.pop_front();
		std::string res = std::get<0>(p);
		int const i = std::get<1>(p), j = std::get<2>(p), index = std::get<3>(p);
		if(res == word) { return true; }
		if(index >= limit) { continue; }
		if(not visited[i][j]) {
		    visited[i][j] = true;
		    for(direction const &dir: dirs) {
			int const h = dir.first + i, k = dir.second + j;
			if(h >= 0 and k >= 0 and h < r and k < c and board[h][k] == word[index]) {
			    res += board[h][k];
			    t.push_back({ res, h, k, index+1});
			}
		    }
		}
	    }
	}
	return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // int const r = board.size(), c = board[0].size();
	std::deque<element> t;
	t.push_back({"a", 0, 0, 1});
	bfs_check(board, words.back(), t);
	// for(std::string const &word: words) {
	//     t.clear();
	//     int const first = word[0];
	//     for(int i = 0; i < r; ++i) {
	// 	for(int j = 0; j < c; ++j) {
	// 	    if(first == board[i][j]) {
	// 		t.push_back({std::string(1, first), i, j, 1});
			
	// 	    }
	// 	}
	//     }
	//     std::fprintf(stdout, "Checking for {%s}\n", word.c_str());
	//     if(bfs_check(board, word, t)) { ans.push_back(word); }
	// }

	return ans;
    }
};

int main() {
    // std::vector<std::vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    // std::vector<std::string> words = {"oath","pea","eat","rain"};

    std::vector<std::vector<char>> board = {
	{'a','a','a','a','a','a','a','a','a','a','a','a'},
	{'a','a','a','a','a','a','a','a','a','a','a','a'},
	{'a','a','a','a','a','a','a','a','a','a','a','a'},
	{'a','a','a','a','a','a','a','a','a','a','a','a'},
	{'a','a','a','a','a','a','a','a','a','a','a','a'},
	{'a','a','a','a','a','a','a','a','a','a','a','a'},
	{'a','a','a','a','a','a','a','a','a','a','a','a'},
	{'a','a','a','a','a','a','a','a','a','a','a','a'},
	{'a','a','a','a','a','a','a','a','a','a','a','a'},
	{'a','a','a','a','a','a','a','a','a','a','a','a'},
	{'a','a','a','a','a','a','a','a','a','a','a','a'},
	{'a','a','a','a','a','a','a','a','a','a','a','a'}};
    
    std::vector<std::string> words = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    Solution sol;
    
    for(std::string const &word: sol.findWords(board, words)) {
	std::fprintf(stdout, "[%s] ", word.c_str());
    }
    std::putc('\n', stdout);


    return 0;
}
