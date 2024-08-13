



#include <bits/stdc++.h>

using std::vector;

struct trie {
public:
    trie* nexts[2];
    int count;
public:
    inline trie() = default;

    inline void insert(int const &num) {
        trie* tmp = this;
        int res = 0, i = 16;
        while(i >= 0) {
            res = (num >> i) & 1;
            if(tmp->nexts[res] == nullptr) {
                tmp->nexts[res] = new trie();
            }
            tmp = tmp->nexts[res];
            tmp->count += 1;
            i = i - 1;
        }
    }

    inline int find(int const &num, int const &bound) {
        trie* tmp = this;
        int i = 16, ans = 0;
        while(i >= 0 and tmp) {
            int const res = (num >> i) & 1, cmp = (bound >> i) & 1;
            if(cmp and tmp->nexts[res]) { // the path tmp->nexts[res] exits when cmp is set i.e bound >= num
                ans += tmp->nexts[res]->count;
            }
            tmp = (cmp) ? tmp->nexts[res ^ 1] : tmp->nexts[res];
            i = i - 1;
        }
        return ans;
    }

    inline ~trie() {
        if(this->nexts[0]) { delete this->nexts[0]; }
        if(this->nexts[1]) { delete this->nexts[1]; }
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
//        int const n = nums.size();
        int res = 0;
        trie *t = new trie();
        for(int const &num: nums) {
            res += t->find(num, high+1) - t->find(num, low);
            t->insert(num);
        }
        delete t;
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1,4,2,7};
    int low = 2, high = 6;
    std::fprintf(stdout, "%d\n", sol.countPairs(nums, low, high));



    return 0;
}
