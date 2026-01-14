



#include <vector>
#include <iostream>
#include <algorithm>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

// this is basically an optimization problem as for the usual `4*n`
// segment tree, MLE gets triggered; hence an iterative bottom-up
// `2*n` variant is used. please note that intervals are half-open
// `[l, r)`.

using i64 = long long;

struct seg_tree {
public:
    using element = std::vector<int>;
public:
    int n;
    std::vector<i64> nums;
    std::vector<element> t;
public:
    inline seg_tree(int const& n, std::vector<i64> const& nums): n(n), nums(nums), t(2*n) {
        for (int i = 0; i < n; ++i) {
            t[n + i].push_back(nums[i]);
        }

        for (int node = n - 1; node > 0; --node) {
            t[node].reserve(t[2*node].size() + t[2*node + 1].size());
            std::merge(t[2*node    ].begin(), t[2*node    ].end(),
                       t[2*node + 1].begin(), t[2*node + 1].end(), std::back_inserter(t[node]));
        }
    }

    inline int find(int left, int right, i64 lower, i64 upper) {
        return find_iterative(left - 1, right, lower, upper); // half-open
    }

    inline int find_iterative(int left, int right, i64 lower, i64 upper) const {
        left += n; right += n;
        int res = 0;
        while (left < right) {
            if (left & 1) {
                res += std::upper_bound(t[left].begin(), t[left].end(), upper) -
                       std::lower_bound(t[left].begin(), t[left].end(), lower);
                ++left;
            }
            if (right & 1) {
                --right;
                res += std::upper_bound(t[right].begin(), t[right].end(), upper) -
                       std::lower_bound(t[right].begin(), t[right].end(), lower);
            }
            left  = left >> 1;
            right = right >> 1;
        }

        return res;
    }
};

struct solution {
    inline static int solve() {
        int n = 0, q = 0;
        std::cin >> n >> q;

        std::vector<i64> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        seg_tree st(n, nums);

        int i = 0, j = 0;
        i64 a = 0, b = 0;
        while (q--) {
            std::cin >> i >> j >> a >> b;
            std::cout << st.find(i, j, a, b) << '\n';
        }

        return 0;
    }
};

int main() { return solution::solve(); }
