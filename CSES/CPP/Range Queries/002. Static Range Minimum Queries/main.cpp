



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

// using sparse table

struct solution {
    inline static void solve() {
        int n = 0, q = 0;
        std::cin >> n >> q;
        int const l = 32 - __builtin_clz(n);
        std::vector<int> logs(n + 1);
        for (int i = 2; i < n + 1; ++i) {
            logs[i] = logs[i >> 1] + 1;
        }
        std::vector<std::vector<int>> sparse(l, std::vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            std::cin >> sparse[0][i];
        }

        for (int i = 1; i < l; ++i) {
            for (int j = 0; j + (1 << i) < n + 1; ++j) {
                int const k = 1 << (i - 1);
                sparse[i][j] = std::min(sparse[i - 1][j], sparse[i - 1][j + k]);
            }
        }

        int from = 0, to = 0;
        while (q--) {
            std::cin >> from >> to;
            --from; --to; // query indices are 1-based
            int const m = logs[to - from + 1];
            std::cout << std::min(sparse[m][from], sparse[m][to - (1 << m) + 1]) << '\n';
        }
    }
};

int main() { solution::solve(); }
