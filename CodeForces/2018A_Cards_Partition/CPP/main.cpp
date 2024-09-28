



#include <bits/stdc++.h>

int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

using longest = long long;

class pooer_solber {
public:
    inline static void solb() {
        longest n, k;
        std::cin >> n >> k;

        longest total = 0LL, maxx = 0LL, num = 0LL;
        for(int i = 0; i < n; ++i) {
            std::cin >> num;
            total += num;
			maxx = std::max(maxx, num);
        }

		for(longest mid = n; 0 < mid; --mid) {
			longest needed = maxx * mid;
			longest adjusted_total = total + (mid - total % mid) % mid; // forcing divisibility by mid

			if(std::max(needed, adjusted_total) - total <= k) {
				std::cout << mid << '\n';
				return;
			}
		}
		return;
    }
};

int main() {
	int cases;
	std::cin >> cases;
	while(cases--) { pooer_solber::solb(); }


	return 0;
}
