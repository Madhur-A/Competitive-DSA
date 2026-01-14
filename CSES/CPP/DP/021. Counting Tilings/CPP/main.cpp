



#include <vector>
#include <iostream>
// #include <defines>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
public:
    inline static constexpr int const mod = 1'000'000'007;
public:
    inline static void solve(int const& r, int const& c) {
        int const s = 1 << r;
        std::vector<int> curr(s, 0), prev;
        curr[0] = 1;

        // all vertical-tiles masks
        std::vector<int> vmask(r - 1);
        for (int j = 0; j < r - 1; ++j) { vmask[j] = 3 << j; }

        int k = c;
        while (k--) {
            prev = std::vector(curr.rbegin(), curr.rend());
            for (int i = 0; i < r - 1; ++i) {
                int const mask = vmask[i]; // adjacent rows masks
                for (int j = 0; j < s; ++j) {
                    if ((j & mask) == 0) { // if not included, then
                        prev[j] = (prev[j] + prev[j | mask]) % mod; // include result of previous configuration
                    }
                }
            }
            curr = prev;
        }

        std::cout << curr[0] << '\n';
    }

    inline static void solve() {
        int r = 0, c = 0;
        std::cin >> r >> c;

        solve(r, c);
    }
};

int main() { solution::solve(); }
