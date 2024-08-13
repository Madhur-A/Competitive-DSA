



#include <bits/stdc++.h>

using std::vector;
using std::string;

struct trie {
public:
    int count = 0;
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
            int const h = word[i]-'a', k = word[n-i]-'a';
            int const y = 26*h + k;
            if(not temp->next.count(y)) {
                temp->next[y] = new trie();
            }
            res += temp->next[y]->count;
            temp = temp->next[y];
        }
        temp->count += 1;
        return res;
    }

    void erase_all(trie* dummy) {
        if(dummy) {
            for(std::pair<int const, trie*> &node: dummy->next) {
                if(node.second) {
                    erase_all(node.second);
                }
            }
            delete dummy;
        }
    }

    ~tried() {
        erase_all(root);
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        tried t;
        long ans = 0;
        for(std::string const &word: words) {
            ans += t.insert(word);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> words = {"a","aba","ababa","aa"};
    std::fprintf(stdout, "%lld\n", sol.countPrefixSuffixPairs(words));

    return 0;
}
