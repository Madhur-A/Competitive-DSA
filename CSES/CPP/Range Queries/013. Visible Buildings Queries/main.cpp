




#include <vector>
#include <iostream>

#define LOG 20

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using i64 = long long;

// notice that the operation of monotonic stack is not associative
// thus in worst case every query could be O(N), with added logic
// of merging; thus using Sparse Table with NGE (Next Greater Element)

struct solution {
    inline static void solve() {
        int n = 0, q = 0;
        std::cin >> n >> q;
        std::vector<i64> heights(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            std::cin >> heights[i];
        }

        std::vector<int> nexts(n + 1, n + 1), t;
        for (int i = n; i > 0; --i) {
            while (not t.empty() and heights[t.back()] <= heights[i]) {
                t.pop_back();
            }
            nexts[i] = not t.empty() ? t.back() : n + 1;
            t.push_back(i);
        }

        std::vector<std::vector<int>> s_table(LOG, std::vector<int>(n + 2));
        for (int i = 1; i < n + 1; ++i) {
            s_table[0][i] = nexts[i];
        }
        s_table[0][n + 1] = n + 1; // active sentinel

        for (int i = 1; i < LOG; ++i) {
            for (int j = 1; j < n + 2; ++j) {
                s_table[i][j] = s_table[i - 1][s_table[i - 1][j]];
            }
        }

        int a = 0, b = 0, res = 1;
        while (q--) {
            std::cin >> a >> b;
            res = 1;
            if (nexts[a] <= b) {
                for (int i = LOG - 1; i > -1; --i) {
                    if (s_table[i][a] <= b) {
                        res += (1 << i);
                        a = s_table[i][a];
                    }
                }
            }
            std::cout << res << '\n';
        }
    }
};


int main() { solution::solve(); }
