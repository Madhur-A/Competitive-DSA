



#include <bits/stdc++.h>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using lnt = long long;

struct seg_tree {
public:
    int n;
    std::vector<lnt> nums;
    std::vector<lnt> t, l, f;
public:
    inline seg_tree(std::vector<lnt> const &nums) : n(nums.size()),
                                                    nums(nums),
                                                    t(4 * n), l(4 * n), f(4 * n, -1) {
        build(0, 0, n - 1);
    }

    inline void build(lnt const &node, lnt const &start, lnt const &finish) {
        if(start == finish) {
            t[node] = nums[start];
        } else {
            lnt const mid = start + ((finish - start) >> 1);
            build(2*node + 1, start, mid);
            build(2*node + 2, mid + 1, finish);
            t[node] = t[2*node + 1] + t[2*node + 2];
        }
    }

    inline void broadcast(lnt const &node, lnt const &start, lnt const &finish) {
        if(f[node] != -1) {
            t[node] = f[node] * (finish - start + 1);
            if(start != finish) {
                f[2*node + 1] = f[node];
                f[2*node + 2] = f[node];
                l[2*node + 1] = 0;
                l[2*node + 2] = 0;
            }
            f[node] = -1;
        }
        if(l[node]) {
            t[node] += l[node] * (finish - start + 1);
            if(start != finish) {
                l[2*node + 1] += l[node];
                l[2*node + 2] += l[node];
            }
            l[node] = 0;
        }
    }

    inline void range_update(lnt const &left, lnt const &right, lnt const &value) {
        return range_update(0, 0, n - 1, left, right, value);
    }

    inline void range_replace(lnt const &left, lnt const &right, lnt const &value) {
        return range_replace(0, 0, n - 1, left, right, value);
    }

    inline lnt range_sum(lnt const &left, lnt const &right) {
        return range_sum(0, 0, n - 1, left, right);
    }

    inline void range_update(lnt const &node, lnt const &start, lnt const &finish,
                             lnt const &left, lnt const &right, lnt const &value) {
        broadcast(node, start, finish);
        if(start > right or finish < left) { return; }
        if(start >= left and finish <= right) {
            l[node] += value;
            broadcast(node, start, finish);
            return;
        }
        lnt const mid = start + ((finish - start) >> 1);
        range_update(2*node + 1, start,      mid, left, right, value);
        range_update(2*node + 2, mid + 1, finish, left, right, value);
        t[node] = t[2*node + 1] + t[2*node + 2];
    }

    inline void range_replace(lnt const &node, lnt const &start, lnt const &finish,
                              lnt const &left, lnt const &right, lnt const &value) {
        broadcast(node, start, finish);
        if(start > right or finish < left) { return; }
        if(start >= left and finish <= right) {
            f[node] = value;
            l[node] = 0;
            broadcast(node, start, finish);
            return;
        }
        lnt const mid = start + ((finish - start) >> 1);
        range_replace(2*node + 1, start,      mid, left, right, value);
        range_replace(2*node + 2, mid + 1, finish, left, right, value);
        t[node] = t[2*node + 1] + t[2*node + 2];
    }

    inline lnt range_sum(lnt const &node, lnt const &start, lnt const &finish,
                         lnt const &left, lnt const &right) {
        broadcast(node, start, finish);
        if(start > right or finish < left)  { return 0; }
        if(start >= left and finish <= right) { return t[node]; }
        lnt const mid = start + ((finish - start) >> 1);
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
    lnt type = 0, to = 0, from = 0, value = 0;
    seg_tree st(nums);
    while(q--) {
        std::cin >> type >> from >> to;
        if(type != 3) { std::cin >> value; }
        if(type == 1) {
            st.range_update(from - 1, to - 1, value);
        } else if(type == 2) {
            st.range_replace(from - 1, to - 1, value);
        } else {
            std::cout << st.range_sum(from - 1, to - 1) << '\n';
        }
    }
}
