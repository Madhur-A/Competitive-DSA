



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using i64 = long long;

[[maybe_unused]]
auto dis = [](auto const& u){ for (std::pair<i64, i64> const &e: u) { std::cout << e.first << ' '; } std::cout << '\n'; };

struct solution {
public:
    using element = std::pair<i64, i64>;
public:
    inline static constexpr i64 const inf = -1E18;
public:
    int n;
    std::vector<element> t;
    std::vector<i64> nums;
public:
    inline element merge(element const& L, element const& R) {
        return std::make_pair(L.first + R.first, std::max(L.second, L.first + R.second)); // [!]
    }

    inline void build(int node, int start, int end) {
        if (start == end) {
            t[node].first = nums[start];
            t[node].second = std::max(0LL, nums[start]);
        } else {
            int const mid = start + ((end - start) >> 1);
            build(2*node + 1, start, mid);
            build(2*node + 2, mid + 1, end);
            t[node] = merge(t[2*node + 1], t[2*node + 2]);
        }
    }

    inline element range_max(int left, int right) { return range_max(0, 0, n - 1, left, right); }

    inline element range_max(int node, int start, int end, int left, int right) {
        if (start > right or left > end) { return std::make_pair(0, inf); }
        if (left <= start and end <= right) { return t[node]; }
        int const mid = start + ((end - start) >> 1);
        element const L = range_max(2*node + 1, start, mid, left, right);
        element const R = range_max(2*node + 2, mid + 1, end, left, right);

        return merge(L, R);
    }

    inline void update(int index, i64 value) { return update(0, 0, n - 1, index, value); }

    inline void update(int node, int start, int end, int index, i64 value) {
        if (start == end) {
            t[node].first  = value;
            t[node].second = std::max(0LL, value);
            nums[index] = value;
        } else {
            int const mid = start + ((end - start) >> 1);
            if (index <= mid) {
                update(2*node + 1, start, mid, index, value);
            } else {
                update(2*node + 2, mid + 1, end, index, value);
            }

            t[node] = merge(t[2*node + 1], t[2*node + 2]);
        }
    }

    inline void solve() {
        int q = 0;
        std::cin >> n >> q;
        nums.resize(n);
        t.resize(4*n, std::make_pair(0LL, 0LL));
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        build(0, 0, n - 1);

        int ls = 0, a = 0; // (load/store, left,
        i64 b = 0;         //                    right/value)
        while (q--) {
            std::cin >> ls >> a >> b;
            if (ls == 1) {
                update(a - 1, b);
            } else {
                std::cout << range_max(a - 1, b - 1).second << '\n';
            }
        }
    }
};

int main() { solution sol; sol.solve(); }
