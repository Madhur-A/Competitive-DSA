



#include <bits/stdc++.h>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using i64 = long long;

struct seg_tree {
public:
    i64 n;
    std::vector<i64> nums, t, l;
public:
    inline seg_tree(std::vector<i64> const &nums): n(nums.size()), nums(nums), t(4 * n), l(4 * n) {
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

    inline void propagate(int node, int start, int finish) {
        if(l[node]) {
            t[node] += l[node] * (finish - start + 1);
            if(start != finish) {
                l[2*node + 1] += l[node];
                l[2*node + 2] += l[node];
            }
            l[node] = 0;
        }
    }

    inline void range_update(int left, int right, int value) {
        return range_update(0, 0, n - 1, left, right, value);
    }

    inline void range_update(int node, int start, int finish, int left, int right, int value) {
        propagate(node, start, finish);
        if(start > right or finish < left) { return; }
        if(left <= start and finish <= right) {
            l[node] += value;
            propagate(node, start, finish);
            return;
        }
        int const mid = start + ((finish - start) >> 1);
        range_update(2*node + 1, start, mid, left, right, value);
        range_update(2*node + 2, mid + 1, finish, left, right, value);
        t[node] = t[2*node + 1] + t[2*node + 2];
    }

    inline i64 range_sum(int index) {
        return range_sum(0, 0, n - 1, index);
    }

    inline i64 range_sum(int node, int start, int finish, int index) {
        propagate(node, start, finish);
        if(start == finish) { return t[node]; }
        int const mid = start + ((finish - start) >> 1);
        return (index <= mid) ?
            range_sum(2*node + 1, start, mid, index) :
            range_sum(2*node + 2, mid + 1, finish, index);
    }
};


int main() {
    i64 n = 0, q = 0;
    std::cin >> n >> q;
    std::vector<i64> nums(n);
    int num = 0, i = 0;
    while(n--) {
        std::cin >> num;
        nums[i++] = num;
    }
    i64 type = 0, to = 0, from = 0, value = 0;
    seg_tree st(nums);
    while(q--) {
        std::cin >> type >> from;
        if(type == 1) {
            std::cin >> to >> value;
            st.range_update(from - 1, to - 1, value);
        } else {
            std::cout << st.range_sum(from - 1) << '\n';
        }
    }
}
