



#include <bits/stdc++.h>

using std::vector;
using std::string;

struct trie {
public:
    trie* next[26];
    bool end = false;
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
    void insert(std::string const &word) {
        trie* temp = root;
        std::string::const_reverse_iterator i = word.rbegin();
        while(i != word.rend()) {
            char const c = *i;
            if(temp->next[c-'a'] == nullptr) {
                temp->next[c-'a'] = new trie();
            }
            temp = temp->next[c-'a'];
            ++i;
        }
        temp->end = true;
    }
    bool search(std::string const &word) {
        trie* temp = root;
        std::string::const_reverse_iterator i = word.rbegin();
        while(i != word.rend()) {
            char const c = *i;
            if(temp and temp->next[c-'a']) {
                temp = temp->next[c-'a'];
                if(temp->end) { return true; }
            } else {
                return false;
            }
            ++i;
        }
        return temp->end;
    }
};

class StreamChecker {
public:
    tried a_tree;
    std::string buffer;
public:
    StreamChecker(vector<string>& words) {
        for(std::string word: words) {
            a_tree.insert(word);
        }
    }
    
    bool query(char letter) {
        buffer += letter;
        return a_tree.search(buffer);
    }
};


/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main() {}
