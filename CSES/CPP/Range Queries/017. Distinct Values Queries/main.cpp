



#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <unordered_map>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

// usual mechanism would trigger TLE/MLE, since this is more or less
// an optimization problem; the often-used trick here is that inverting
// the order of priori. instead of processing queries one-by-one and
// building the tree in a single batch; it would be efficient to process
// updates one-by-one and queries, in a batch. other than that, it is usual
// prefix sum with coordinate compression tree (also known as frequency
// segment tree). see `Increasing Subsequence II` in the DP section for
// a much shorter Fenwick approach.

using i64 = long long;

struct seg_tree {
public:
    int n;
    std::vector<int> t;
public:
    inline seg_tree(int const &n): n(n), t(4 * n) {
    }

    inline void update(int index, int value) {
        return update(0, 0, n - 1, index, value);
    }

    inline void update(int node, int start, int end, int index, int value) {
        if (start == end) {
            t[node] = value;
        } else {
            int const mid = start + ((end - start) >> 1);
            if (index <= mid) {
                update(2*node + 1, start, mid, index, value);
            } else {
                update(2*node + 2, mid + 1, end, index, value);
            }
            t[node] = t[2*node + 1] + t[2*node + 2];
        }
    }

    inline int find(int left, int right) {
        return find(0, 0, n - 1, left, right);
    }

    inline int find(int node, int start, int end, int left, int right) {
        if (right < start or end < left) { return 0; }
        if (left <= start and end <= right) { return t[node]; }
        int const mid = start + ((end - start) >> 1);
        return
            find(2*node + 1, start, mid, left, right) +
            find(2*node + 2, mid + 1, end, left, right);
    }
};

struct solution {
    inline static void solve() {
        int n = 0, q = 0;
        std::cin >> n >> q;

        std::vector<i64> nums(n);
        std::vector<std::vector<std::pair<int, int>>> queries(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        int h = 0, k = 0;
        for (int i = 0; i < q; ++i) {
            std::cin >> h >> k;
            queries[h - 1].emplace_back(k - 1, i);
        }

        seg_tree st(n);
        std::vector<int> res(q, -1);
        std::unordered_map<i64, int> indices;

        for (int i = n - 1; i > -1; --i) {
            if (indices.count(nums[i])) {
                st.update(indices[nums[i]], 0);
            }
            indices[nums[i]] = i;
            st.update(i, 1);

            for (std::pair<int, int> const &query: queries[i]) {
                res[query.second] = st.find(i, query.first);
            }
        }

        std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, "\n"));
    }
};

int main() { solution::solve(); }
