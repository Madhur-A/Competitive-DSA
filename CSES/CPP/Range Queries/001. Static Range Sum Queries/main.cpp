



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
    inline static void solve() {
        int n = 0, q = 0;
        std::cin >> n >> q;
        std::vector<long> prefix(n + 1);
        for (int i = 1, num = 0; i < n + 1; ++i) {
            std::cin >> num;
            prefix[i] = prefix[i - 1] +  num;
        }

        int from = 0, to = 0;
        while (q--) {
            std::cin >> from >> to;
            std::cout << prefix[to] - prefix[from - 1] << '\n';
        }
    }
};

int main() { solution::solve(); }
