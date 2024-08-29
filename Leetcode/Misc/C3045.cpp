



#include <bits/stdc++.h>

using std::string;
using std::vector;

struct trie {
public:
    int kount = 0;
    std::unordered_map<int, trie*> next;
};

struct tried {
public:
    trie* root;
public:
    tried(): root(new trie()) {
    }
    
    int insert(std::string const &word) {
        trie* temp = root;
        int res = 0;
        int const n = word.length() - 1;
        for(int i = 0; i < n+1; ++i) {
            int const h = word[i] - 'a', k = word[n-i] - 'a';
            int const y = 26*h + k;
            if(temp->next.count(y) == 0) {
                temp->next[y] = new trie();
            }
            res += temp->next[y]->kount;
            temp = temp->next[y];
        }
        temp->kount += 1;
        return res;
    }

    void rx_erase(trie* t) {
	if(t) {
	    for(std::pair<int const, trie*> &child: t->next) {
		rx_erase(child.second);
	    }
	    delete t;
	}
    }

    ~tried() { rx_erase(root); }
};

class Solution {
public:
    tried t;
    long ans = 0;
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        for(std::string const &word: words) {
            ans += t.insert(word);
        }
        return ans;
    }
};

int main() {
    std::vector<std::string> words = {"a","aba","ababa","aa"};
    Solution sol;
    std::fprintf(stdout, "%lld\n", sol.countPrefixSuffixPairs(words));



    return 0;
}
