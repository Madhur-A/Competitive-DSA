




#include <bits/stdc++.h>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using lnt = long long;

struct seg_tree {
public:
    struct indices { lnt value; int index; };
public:
    lnt n;
    std::vector<lnt> nums;
    std::vector<indices> t;
public:
    inline seg_tree(std::vector<lnt> const &nums): n(nums.size()), nums(nums), t(4 * n) {
        build(0, 0, n - 1);
    }

    inline void build(int const &node, int const &start, int const &finish) {
        if(start == finish) {
            t[node].value = nums[start];
            t[node].index = start;
        } else {
            int const mid = start + ((finish - start) >> 1);
            build(2*node + 1, start, mid);
            build(2*node + 2, mid + 1, finish);
            t[node] = (t[2*node + 2].value <= t[2*node + 1].value) ? t[2*node + 1] : t[2*node + 2];
        }
    }

    inline int range_find(int const &target) {  return range_find(0, 0, n - 1, target); }

    inline int range_find(int const &node, int const &start, int const &finish, int const &target) {
        if(t[node].value < target) { return -1; }
        if(start == finish) {
            t[node].value = t[node].value - target; return t[node].index;
        }
        int const mid = start + ((finish - start) >> 1);
        int res = 0;
        if(target <= t[2*node + 1].value) {
            res = range_find(2*node + 1, start, mid, target);
            t[node] = (t[2*node + 2].value <= t[2*node + 1].value) ? t[2*node + 1] : t[2*node + 2];
        } else {
            res = range_find(2*node + 2, mid + 1, finish, target);
            t[node] = (t[2*node + 2].value <= t[2*node + 1].value) ? t[2*node + 1] : t[2*node + 2];
        }
        return res;
    }
};

int main() {
    int n = 0, m = 0, i = 0;
    std::cin >> n >> m;
    std::vector<lnt> nums(n);
    while(i < n) { std::cin >> nums[i++]; }
    seg_tree st(nums);
    int query = 0;
    while(m > 0) {
        std::cin >> query;
        std::cout << 1 + st.range_find(query) << " ";
        m = m - 1;
    } std::cout << '\n';


    return 0;
}
