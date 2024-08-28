



#include <bits/stdc++.h>

using std::vector;
using std::string;

struct trie {
public:
    int count = 1;
    trie* next[26];
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
        for(char const &c: word) {
            if(temp->next[c-'a'] == nullptr) {
                temp->next[c-'a'] = new trie();
            } else {
                temp->next[c-'a']->count += 1;
            }
            temp = temp->next[c-'a'];
        }
    }
    
    int search(std::string const &word) {
        trie* temp = root;
        int res = 0;
        for(char const &c: word) {
            if(temp->next[c-'a']) {
                res += temp->next[c-'a']->count;
            } else {
                return res;
            }
            temp = temp->next[c-'a'];
        }
        return res;
    }

    inline void rx_erase(trie *t) {
	if(t) {
	    for(int i = 0; i < 26; ++i) {
		rx_erase(t->next[i]);
	    }
	    delete t;
	}
    }

    inline ~tried() {
	rx_erase(root);
    }
};


class Solution {
public:
    tried t;
    std::vector<int> ans;
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for(std::string const &word: words) {
            t.insert(word);
        }
            for(std::string const &word: words) {
            ans.push_back(t.search(word));
        }
        return ans;
    }
};

int main() {

    return 0;
}
