



#include <bits/stdc++.h>

using std::vector;
using std::string;

class Solution {
public:
    std::priority_queue<std::pair<int, long>, std::vector<std::pair<int, long>>, std::greater<std::pair<int, long>>> t;
    std::unordered_set<long> seen;
public:
    long power(int n, long res = 1L) {
        return (n == 0) ? res : power(n - 1, res * 10L);
    }

    long rv_num(long const &number) {
        long res = 0L, curr = number;
        while(curr > 0) { res = res * 10L + (curr % 10); curr = curr / 10; }
        return res;
    }

    bool is_palindrome(long const &number) {
        return number == rv_num(number);
    }

    long as_num(std::string const &number) {
        long res = 0;
        std::string::const_iterator left = number.begin(), right = number.end();
        while(left < right) { res = 10 * res + (*left++ - '0'); }

        return res;
    }

    long select(long const &num, int const &offset) {
        if(num > 17) {
            int const len = std::floor(std::log10(num)) + 1;
            int const mid = len >> 1;

            long const div = power(mid);
            long const res = (num / div) + offset;

            return res * div + ((len & 1) ? rv_num(res / 10) : rv_num(res));
        }
        return num + offset;
    }

    string nearestPalindromic(string s) {
        long const number = as_num(s);

        t.push({0, number - 1});
        t.push({0, number + 1});

        while(not t.empty()) {
            std::pair<int, long> const popped = t.top(); t.pop();
            if(is_palindrome(popped.second) and popped.second != number) { return std::to_string(popped.second); }
            if(not seen.count(popped.second)) {
                seen.insert(popped.second);
                for(int const &offset: {-1, 0, 1}) {
                    long const new_number = select(popped.second, offset);
                    if(not seen.count(new_number)) {
                        t.push({std::abs(number - new_number), new_number});
                    }
                }
            }

        }

        return "-1";
    }
};

int main() {
    Solution sol;
    std::string num = "123";
    std::fprintf(stdout, "%s\n", sol.nearestPalindromic(num).c_str());

    return 0;
}
