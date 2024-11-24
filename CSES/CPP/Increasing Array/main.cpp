




#include <bits/stdc++.h>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using lnt = long long;

int main() {
    lnt n = 0;
    lnt curr = 0, prev = LLONG_MIN, res = 0;
    std::cin >> n;

    while(--n >= 0) {
        std::cin >> curr;
        res += (curr < prev) ? (prev - curr) : 0;
        prev = std::max(prev, curr);
    }

    std::cout << res << '\n';
}
