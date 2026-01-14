



#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
public:
    inline static constexpr int const mod = 1'000'000'007;
public:
    // the idea is to collect all possible positions of all unique
    // numbers and then enumerating an online prefix sum over it.
    inline static void solve(std::vector<int> const& numbers) {
        int const n = numbers.size();
        std::vector<int> nums(numbers.begin(), numbers.end());
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        int const z = nums.size() + 1;

        int res = 0, ans = 0;
        std::vector<int> fenwick(z);
        for (int i = 0, j = 0; j < n; ++j) {
            // int const index = find_left(nums, numbers[j]);
            // since `algorithm` is already included, then why not use it to the fullest
            int const index = std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), numbers[j]));
            i = index, res = 0;
            while (i > 0) { // find routine for fenwick
                res = (res + 0L + fenwick[i]) % mod;
                i -= (i & -i);
            }

            ans = (ans + 1L + res) % mod;
            i = index + 1;
            while (i < z) { // update routine for fenwick
                fenwick[i] = (fenwick[i] + 1L + res) % mod;
                i += (i & -i);
            }
        }

        std::cout << ans << '\n';
    }

    inline static void solve() {
        int n = 0;
        std::cin >> n;
        std::vector<int> nums(n);
        for (int i = 0; i < n; std::cin >> nums[i], ++i);

        solve(nums);
    }
};

int main() { solution::solve(); }
