



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

// using fenwick tree

struct solution {
public:
    using i64 = long long;
public:
    inline static void update(std::vector<i64>& prefix, int const& index, i64 const& value) {
        int const n = prefix.size();
        int i = index;
        while (i < n) { prefix[i] += value; i += (i & -i); }
    }

    inline static i64 get(std::vector<i64> const& prefix, int const& index) {
        int i = index;
        i64 res = 0LL;
        while (i > 0) { res += prefix[i]; i -= (i & -i);  }

        return res;
    }

    inline static void solve() {
        int n = 0, q = 0;
        std::cin >> n >> q;
        std::vector<i64> nums(n);
        std::vector<i64> fenwick(n + 1);

        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
            update(fenwick, i + 1, nums[i]);
        }

        i64 ls = 0, a = 0, b = 0; // (load/store, left, right/value)
        while (q--) {
            std::cin >> ls >> a >> b;
            if (ls == 1) {
                update(fenwick, a, b - nums[a - 1]);
                nums[a - 1] = b;
            } else {
                std::cout << get(fenwick, b) - get(fenwick, a - 1) << '\n';
            }
        }
    }
};

int main() { solution::solve(); }
