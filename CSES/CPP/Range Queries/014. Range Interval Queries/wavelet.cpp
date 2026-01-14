



#include <vector>
#include <iostream>
#include <algorithm>

auto  _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; };
auto __ = _();

using i64 = long long;

struct wavelet_t {
public:
    using itr_t = std::vector<i64>::iterator;
public:
    i64 minn, maxx;
    wavelet_t *tl = nullptr, *tr = nullptr;
    std::vector<i64> left_values;
public:
    inline wavelet_t(itr_t bgn, itr_t end, i64 minn, i64 maxx): minn(minn), maxx(maxx) {
        if (bgn < end and minn != maxx) {
            i64 const mid = minn + ((maxx - minn) >> 1);
            left_values.reserve(end - bgn + 1); // optimization gimmick (since this is more or less an optimization problem)
            left_values.push_back(0);

            for (std::vector<i64>::const_iterator it = bgn; it != end; ++it) {
                left_values.push_back(left_values.back() + (*it <= mid));
            }

            itr_t pivot = std::stable_partition(bgn, end, [mid](i64 const& e) { return e <= mid; }); // O(N) !![bottleneck]!!
            tl = new wavelet_t(bgn, pivot, minn, mid);
            tr = new wavelet_t(pivot, end, mid + 1, maxx);
        }
    }

    inline int count(int left, int right, i64 a, i64 b) {
        if (left > right or b < minn or a > maxx) { return 0; }
        if (a <= minn and maxx <= b) { return right - left + 1; }
        i64 const L = left_values[left - 1], R = left_values[right];

        return
            (tl ? tl->count(L + 1, R, a, b) : 0) +
            (tr ? tr->count(left - L, right - R, a, b) : 0);
    }
};

struct solution {
    inline static void solve() {
        int n = _(), q = _(); // keep flushing
        std::cin >> n >> q;
        std::vector<i64> nums;
        nums.resize(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        std::vector<int> sorted(nums.begin(), nums.end());
        std::sort(sorted.begin(), sorted.end());
        sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
        for (int i = 0; i < n; ++i) {
            nums[i] = std::lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
        }

        wavelet_t t(nums.begin(), nums.end(), 1, sorted.size());

        int i = 0, j = 0;
        i64 a = 0, b = 0;
        while (q--) {
            std::cin >> i >> j >> a >> b;
            int const c = std::lower_bound(sorted.begin(), sorted.end(), a) - sorted.begin() + 1;
            int const d = std::upper_bound(sorted.begin(), sorted.end(), b) - sorted.begin();
            if (c > d) {
                std::cout << "0\n";
            } else {
                std::cout << t.count(i, j, c, d) << '\n';
            }
        }
    }
};

int main() { solution::solve(); }
