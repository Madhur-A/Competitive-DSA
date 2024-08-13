



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    inline static constexpr int const prm = 103;
    inline static constexpr int const mod = 572815538; // modular multiplicative inverse of prime = 103
public:
    std::vector<long> hashes;
    std::vector<long> powers;
public:
    void construct_hashes(std::string const &word) {
        int const n = word.length();
        hashes.resize(n + 1);
        powers.resize(n + 1); powers[0] = 1L;
        for(int i = 1; i < n+1; ++i) {
            powers[i] = (powers[i-1] * prm) % mod;
            hashes[i] = (hashes[i-1] * prm + (word[i-1] - 'a')) % mod;
        }
    }
public:
    string longestPrefix(string word) {
        int const n = word.length();
        construct_hashes(word);
        for(int i = n-1; i > 0; --i) {
            if(hashes[i] == (((hashes[n] - hashes[n-i] * powers[i]) % mod) + mod) % mod) {
                return word.substr(0, i);
            }
        }
        return "";
    }
};

int main() {
    Solution sol;
    std::string word = "level";
    std::fprintf(stdout, "%s\n", sol.longestPrefix(word).c_str());

    return 0;
}
