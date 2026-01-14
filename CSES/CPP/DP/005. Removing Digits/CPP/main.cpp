



#include <vector>
#include <iostream>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
public:
    static constexpr int const mod = 1'000'000'007;
public:
    inline static int max_of(int num) {
        int res = 0;
        while (num) { res = std::max(res, num % 10); num /= 10; }
        return res;
    }

    inline static int count(int const& num) {
        return num == 0 ? 0 : 1 + count(num - max_of(num));
    }

    inline static void solve() {
        int n = 0;
        std::cin >> n;
        std::cout << count(n) << '\n';
    }
};

int main() { solution::solve(); }
