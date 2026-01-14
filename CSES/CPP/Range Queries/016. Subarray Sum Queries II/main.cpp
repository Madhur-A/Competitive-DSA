



#include <array>
#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using i64 = long long;
const i64 INF = 8E18;

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

    inline i64 find(int left, int right) {
        return std::max(0LL, find(0, 0, n - 1, left - 1, right - 1)[0]);
    }

    inline element find(int node, int start, int end, int left, int right) {
        if (right < start or end < left) {
            return {0, 0, -INF, -INF};
        }
        if (left <= start and end <= right) {
            return t[node];
        }
        int const mid = start + ((end - start) >> 1);
        element const L = find(2*node + 1, start, mid, left, right);
        element const R = find(2*node + 2, mid + 1, end, left, right);
        if (L[2] <= -(INF >> 1)) { return R; }
        if (R[2] <= -(INF >> 1)) { return L;  }


        i64 const a = std::max(std::max(L[0], R[0]), std::max(L[1] + R[1], L[3] + R[2]));
        i64 const b = L[1] + R[1];
        i64 const c = std::max(L[2], L[1] + R[2]);
        i64 const d = std::max(R[3], L[3] + R[1]);

        return {a, b, c, d};
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

        int i = 0, j = 0;
        while (q--) {
            std::cin >> i >> j;
            std::cout << st.find(i, j) << '\n';
        }
    }
};


int main() { solution::solve(); }
