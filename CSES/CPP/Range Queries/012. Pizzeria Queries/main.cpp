




#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using i64 = long long;

struct seg_tree {
public:
    inline static constexpr i64 const inf = 1E18;
public:
    int n;
    std::vector<i64> t;
public:
    inline seg_tree(int const& n): n(n), t(4*n) {
    }

    inline void update(i64 index, i64 value) { return update(0, 0, n - 1, index, value); }

    inline void update(int node, int start, int end, i64 index, i64 value) {
        if (start == end) {
            t[node] = value;
        } else {
            int const mid = start + ((end - start) >> 1);
            if (index <= mid) {
                update(2*node + 1, start, mid, index, value);
            } else {
                update(2*node + 2, mid + 1, end, index, value);
            }
            t[node] = std::min(t[2*node + 1], t[2*node + 2]);
        }
    }

    inline i64 find(int left, int right) { return find(0, 0, n - 1, left, right); }

    inline i64 find(int node, int start, int end, int left, int right) {
        if (right < start or end < left) { return inf; }
        if (left <= start and end <= right) { return t[node]; }

        int const mid = start + ((end - start) >> 1);
        return std::min(find(2*node + 1, start, mid, left, right),
                        find(2*node + 2, mid + 1, end, left, right));
    }
};

struct solution {
    inline static void solve() {
        int n = 0, q = 0;
        std::cin >> n >> q;
        std::vector<i64> nums(n);
        seg_tree l_tree(n), r_tree(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
            l_tree.update(i, nums[i] - i); //[!] implicit but critical assumption
            r_tree.update(i, nums[i] + i); //    see the `find` call below.
        }

        int ls = 0, k = 0; // (load/store, left,
        i64 x = 0; //                            right/value)
        while (q--) {
            std::cin >> ls;
            if (ls == 1) {
                std::cin >> k >> x;
                nums[k - 1] = x;
                l_tree.update(k - 1, x - k + 1);
                r_tree.update(k - 1, x + k - 1);
            } else {
                std::cin >> k;
                std::cout << std::min(l_tree.find(0, k - 1) + (k - 1),
                                      r_tree.find(k - 1, n - 1) - (k - 1)) << '\n';
            }
        }
    }
};

int main() { solution::solve(); }
