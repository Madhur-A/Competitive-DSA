



#include <bits/stdc++.h>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using lnt = long long;

struct seg_tree {
public:
    lnt n;
    std::vector<lnt> nums, t;
public:
    inline seg_tree(std::vector<lnt> const &nums): n(nums.size()), nums(nums), t(4 * n) {
        build(0, 0, n - 1);
    }

    inline void build(int node, int start, int finish) {
        if(start == finish) {
            t[node] = nums[start];
        } else {
            int const mid = start + ((finish - start) >> 1);
            build(2*node + 1, start, mid);
            build(2*node + 2, mid + 1, finish);
            t[node] = t[2*node + 1] + t[2*node + 2];
        }
    }

    inline lnt range_sum(int left, int right) {
        return range_sum(0, 0, n - 1, left, right);
    }

    inline lnt range_sum(int node, int start, int finish, int left, int right) {
        if(start > right or finish < left) { return 0; }
        if(left <= start and finish <= right) { return t[node]; }
        int const mid = start + ((finish - start) >> 1);
        return
            range_sum(2*node + 1, start, mid, left, right) +
            range_sum(2*node + 2, mid + 1, finish, left, right);
    }
};


int main() {
    lnt n = 0, q = 0;
    std::cin >> n >> q;
    std::vector<lnt> nums(n);
    int num = 0, i = 0;
    while(n--) {
        std::cin >> num;
        nums[i++] = num;
    }
    lnt to = 0, from = 0;
    seg_tree st(nums);
    while(q--) {
        std::cin >> from >> to;
        std::cout << st.range_sum(from - 1, to - 1) << '\n';
    }
}
