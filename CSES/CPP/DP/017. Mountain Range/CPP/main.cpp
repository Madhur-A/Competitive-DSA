



#include <vector>
#include <iostream>
#include <algorithm>

struct solution {
    inline static constexpr int const inf = 1 << 30;
public:
    inline static void solve(std::vector<int> const& heights) {
        int const n = heights.size() - 2;

        // from left
        std::vector<int> left(n + 2, 0), t;
        for (int i = 1; i < n + 1; ++i) {
            while (not t.empty() and heights[t.back()] <= heights[i]) { t.pop_back(); }
            left[i] = t.empty() ? 0 : t.back();
            t.push_back(i);
        }

        // from right
        std::vector<int> right(n + 2, n + 1); t.clear();
        for (int i = n; i > 0; --i) {
            while (not t.empty() and heights[t.back()] <= heights[i]) { t.pop_back(); }
            right[i] = t.empty() ? n + 1 : t.back();
            t.push_back(i);
        }

        std::vector<std::pair<int, int>> mountains; // (height, index)
        for (int i = 1; i < n + 1; ++i) {
            mountains.emplace_back(heights[i], i);
        }
        std::sort(mountains.begin(), mountains.end());

        std::vector<int> dp(n + 2, 0);
        int res = 0, last_height = -1;
        std::vector<std::pair<int, int>>::const_reverse_iterator mountain = mountains.rbegin();

        while (mountain != mountains.rend()) {
            int const h = mountain->first, i = mountain->second;
            if (h != last_height) { last_height = h; }
            dp[i] = std::max(dp[left[i]], dp[right[i]]) + 1;
            res = std::max(res, dp[i]);
            ++mountain;
        }

        std::cout << res << '\n';
    }

    inline static void solve() {
        int n = 0;
        std::cin >> n;
        std::vector<int> heights(n + 2);
        for (int i = 1; i < n + 1; ++i) { std::cin >> heights[i]; }
        heights[0] = heights[n + 1] = inf;

        solve(heights);
    }
};

int main() { solution::solve(); }
