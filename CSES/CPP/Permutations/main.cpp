




#include <bits/stdc++.h>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using lnt = long long;

int main() {
    lnt n = 0;
    std::cin >> n;
    if(n != 2 and n != 3) {
        lnt odd = 1, even = 2;
        while(even <= n) {
            std::cout << even << ' ';
            even += 2;
        }
        while(odd <= n) {
            std::cout << odd << ' ';
            odd += 2;
        }
        std::cout << '\n';
    } else {
        std::cout << "NO SOLUTION\n";
    }
}
