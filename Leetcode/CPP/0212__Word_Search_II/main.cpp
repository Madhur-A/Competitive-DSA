



#include <bits/stdc++.h>

using std::vector;
using std::string;

struct trie {
public:
    trie* next[26];
    bool end = false;
    int index = -1;
};

struct tried {
public:
    trie* root;
public:
    tried(): root(new trie()) {
        for(int i = 0; i < 26; ++i) {
            root->next[i] = nullptr;
        }
    }

    void insert(std::string const &word, int index) {
        trie* temp = root;
        for(char const &c: word) {
            if(temp->next[c-'a'] == nullptr) {
                temp->next[c-'a'] = new trie();
            }
            temp = temp->next[c-'a'];
        }
        temp->end = true;
        temp->index = index;
    }

    void rx_delete(trie* r) {
        if(r) {
            for(int i = 0; i < 26; ++i) {
                rx_delete(r->next[i]);
            }
            delete r;
        }
    }

    ~tried() {
        rx_delete(root);
    }
};

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    std::vector<std::string> ans;
public:
    void dfs(vector<vector<char>>& grid, vector<string>& words, trie* rye, int i, int j) {
        int const r = grid.size(), c = grid[0].size();
        if(i >= 0 and j >= 0 and i < r and j < c and grid[i][j] != '*') {
            char const ch = grid[i][j];
            if(rye->next[ch-'a'] == nullptr) { return; }
            rye = rye->next[ch-'a'];
            if(rye->end) { ans.push_back(words[rye->index]); rye->end = false; rye->index = -1; }
            grid[i][j] = '*';
            for(direction const &dir: dirs) {
                int const h = dir.first + i, k = dir.second + j;
                dfs(grid, words, rye, h, k);
            }
            grid[i][j] =  ch;
        }
        return;
    }

    vector<string> findWords(vector<vector<char>>& grid, vector<string>& words) {
        int const n = words.size();
        int const r = grid.size(), c = grid[0].size();
        tried* rye = new tried();
        for(int i = 0; i < n; ++i) {
            rye->insert(words[i], i);
        }
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                dfs(grid, words, rye->root, i, j);
            }
        }

        delete rye;
        return ans;
    }
};

int main() {
     std::vector<std::vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
     std::vector<std::string> words = {"oath","pea","eat","rain"};

     Solution sol;

     for(std::string const &word: sol.findWords(board, words)) {
         std::fprintf(stdout, "%s\n", word.c_str());
     }
     std::putc('\n', stdout);


     return 0;
}
