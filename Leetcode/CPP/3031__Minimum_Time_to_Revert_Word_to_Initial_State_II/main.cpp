



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

    long get(int const &i, int const &j) {
        return ((hashes[j] - hashes[i-1] * powers[j-i+1] % mod) + mod) % mod;
    }
public:
    int minimumTimeToInitialState(string word, int k) {
        int const n = word.length();
        construct_hashes(word);
        for(int i = k; i < n; i += k) {
            if(get(1, n-i) == get(i+1, n)) {
                return i/k;
            }
        }
        return (n + k - 1) / k;
    }
};


int main() {
    std::string word = "abacaba";
    int k = 3;
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minimumTimeToInitialState(word, k));


    return 0;
}
