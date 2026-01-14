



#include <vector>
#include <iostream>
#include <iterator>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using i64 = long long;

class seg_tree {
public:
    int n;
    std::vector<i64> t, l;
public:
    inline seg_tree(int const& n): n(n), t(4 * n), l(4 * n) {
    }

    inline void propagate(int node, int len) {
        if (l[node]) {
            t[2*node + 1] += l[node] * (len >> 1);
            t[2*node + 2] += l[node] * ((len + 1) >> 1);
            l[2*node + 1] += l[node];
            l[2*node + 2] += l[node];
            l[node] = 0;
        }
    }

    inline void update(int left, int right, i64 value) {
        update(0, 0, n, left, right, value);
    }

    inline void update(int node, int start, int end, int left, int right, i64 value) {
        if (right <= start or end <= left) { return; }
        if (left <= start and end <= right) {
            t[node] += (end - start) * value;
            l[node] += value;
            return;
        }
        propagate(node, end - start);
        int const mid = start + ((end - start) >> 1);
        update(2*node + 1, start, mid, left, right, value);
        update(2*node + 2, mid, end, left, right, value);
        t[node] = t[2*node + 1] + t[2*node + 2];
    }

    inline i64 find(int left, int right) {
        return find(0, 0, n, left, right);
    }

    inline i64 find(int node, int start, int end, int left, int right) {
        if (right <= start or end <= left) { return 0; }
        if (left <= start and end <= right) {
            return t[node];
        }
        propagate(node, end - start);
        int const mid = start + ((end - start) >> 1);
        return
            find(2*node + 1, start, mid, left, right) +
            find(2*node + 2, mid, end, left, right);
    }
};

struct solution {
    inline static void solve() {
        int n = 0, q = 0;
        std::cin >> n >> q;

        seg_tree st(n);

        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
            st.update(i, i + 1, -nums[i]);
        }

        std::vector<std::vector<std::pair<int, int>>> queries(n);
        std::vector<i64> res(q);

        for (int i = 0, l = 0, r = 0; i < q; ++i) {
            std::cin >> l >> r;
            l -= 1;
            queries[l].emplace_back(r, i);
        }

        std::vector<int> t;
        t.push_back(n);

        for (int i = n - 1; i > -1; --i) {
            while (t.back() < n and nums[t.back()] <= nums[i]) {
                int const j = t.back();
                t.pop_back();
                st.update(j, t.back(), -nums[j]);
            }
            st.update(i, t.back(), nums[i]);
            t.push_back(i);

            for (std::pair<int, int> const& e: queries[i]) {
                int const r = e.first, j = e.second;
                res[j] = st.find(i, r);
            }
        }

        std::copy(res.begin(), res.end(), std::ostream_iterator<i64>(std::cout, "\n"));
    }
};

int main() { solution::solve(); }
