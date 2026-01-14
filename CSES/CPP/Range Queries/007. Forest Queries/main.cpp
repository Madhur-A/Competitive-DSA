



#include <bits/stdc++.h>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

using i64 = long long;

void prefix_sum(std::vector<std::vector<i64>> &grid) {
    int const r = grid.size(), c = grid[0].size();
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            int const left = (j - 1) > -1 ? grid[i][j - 1] : 0;
            int const up   = (i - 1) > -1 ? grid[i - 1][j] : 0;
            int const diag = (i - 1) > -1 and (j - 1) > -1 ? grid[i - 1][j - 1] : 0;
            grid[i][j] = grid[i][j] + left + up - diag;
        }
    }
}

int main() {
    int r = 0, q = 0;
    std::cin >> r >> q;
    std::vector<std::vector<i64>> nums(r, std::vector<i64>(r));
    i64 i = 0, j = 0;
    std::string line;
    std::getline(std::cin, line);
    while(r) {
        std::getline(std::cin, line);
        for(char const &c: line) {
            if(c == '*') { nums[i][j] = 1; }
            j  += 1;
        }
        j = 0;
        i = i + 1;
        r = r - 1;
    }
    prefix_sum(nums);
    int x = 0, y = 0, h = 0, k = 0;
    while(q) {
        std::cin >> x >> y >> h >> k;
        x = x - 1; y = y - 1; h = h - 1; k = k - 1;
        std::cout << nums[h][k] - (x > 0 ? nums[x - 1][k] : 0) - (y > 0 ? nums[h][y - 1] : 0) + ((x > 0 and y > 0) ? nums[x - 1][y - 1] : 0) << '\n';
        q = q - 1;
    }


    return 0;
}
