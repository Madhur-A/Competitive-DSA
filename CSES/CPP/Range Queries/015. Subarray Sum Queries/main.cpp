



#include <array>
#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using i64 = long long;

struct seg_tree {
public:
    using element = std::array<i64, 4>; // {max_subsum, total_sum, prefix, suffix}
public:
    int n;
    std::vector<i64> nums;
    std::vector<element> t;
public:
    inline seg_tree(std::vector<i64> const &nums): n(nums.size()), nums(nums), t(4 * n) {
        build(0, 0, n - 1);
    }

    inline void merge(int node, int left, int right) {
        t[node][1] = t[left][1] + t[right][1]; // total_sum
        t[node][2] = std::max(t[left][2], t[left][1] + t[right][2]); // max prefix
        t[node][3] = std::max(t[right][3], t[right][1] + t[left][3]); // max suffix

        i64 const a = t[left][0], b = t[right][0], c = t[node][1];
        i64 const d = t[left][3] + t[right][2];

        t[node][0] = std::max(std::max(a, b), std::max(c, d)); // max sub sum (4-way comparisons)
    }

    inline void build(int node, int start, int end) {
        if(start == end) {
            t[node] = {nums[start], nums[start], nums[start], nums[start]};
        } else {
            int const mid = start + ((end - start) >> 1);
            build(2*node + 1, start, mid);
            build(2*node + 2, mid + 1, end);
            merge(node, 2*node + 1, 2*node + 2);
        }
    }

    inline void update(int index, i64 value) {
        return update(0, 0, n - 1, index - 1, value);
    }

    inline void update(int node, int start, int end, int index, i64 value) {
        if(start == end) {
            t[node] = {value, value, value, value};
        } else {
            int const mid = start + ((end - start) >> 1);
            if (index <= mid) {
                update(2*node + 1, start, mid, index, value);
            } else {
                update(2*node + 2, mid + 1, end, index, value);
            }
            merge(node, 2*node + 1, 2*node + 2);
        }
    }
};


struct solution {
    inline static void solve() {
        int n = 0, q = 0;
        std::cin >> n >> q;

        std::vector<i64> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        seg_tree st(nums);

        int k = 0; i64 x = 0;
        while (q--) {
            std::cin >> k >> x;
            st.update(k, x);
            std::cout << std::max(0LL, st.t[0][0]) << '\n';
        }
    }
};


int main() { solution::solve(); }
