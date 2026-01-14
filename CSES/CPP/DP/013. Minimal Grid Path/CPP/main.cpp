



#include <vector>
#include <iostream>
#include <deque>

int _ = [](){ std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); return 0; }();

struct solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[2] = {{0,1},{1,0}};
public:
    inline static void solve() {
        int n = 0;
        std::cin >> n;
        std::vector<std::string> grid(n);

        for (int i = 0; i < n; ++i) { std::cin >> grid[i]; }
        int const r = n, c = n;

        std::string path(1, grid[0][0]);
        std::deque<std::pair<int, int>> t;
        t.push_back(std::make_pair(0, 0));
        std::vector<std::vector<bool>> visited(r, std::vector<bool>(c));

        for (int i = 0; i < r + c - 2; ++i) {
            char candidate = 'Z' + 1;
            for (std::pair<int, int> const& node: t) {
                for (direction const& dir: dirs) {
                    int const h = node.first + dir.first, k = node.second + dir.second;
                    if (h < r and k < c and h > -1 and k > -1) {
                        candidate = std::min(candidate, grid[h][k]);
                    }
                }
            }
            path.operator+=(candidate);
            int const z = t.size();
            for (int _i = 0; _i < z; ++_i) {
                std::pair<int, int> const node = t.front(); t.pop_front();
                for (direction const& dir: dirs) {
                    int const h = node.first + dir.first, k = node.second + dir.second;
                    if (h < r and k < c and h > -1 and k > -1 and not visited[h][k] and grid[h][k] == candidate) {
                        visited[h][k] = true;
                        t.push_back(std::make_pair(h, k));
                    }
                }
            }
        }


        std::cout << path << '\n';
    }
};

int main() { solution::solve(); }


// std::vector<std::vector<std::string>> dp(n, std::vector<std::string>(n));
// int const r = n, c = n;

// dp[0][0] = grid[0][0];

// for (int i = 1; i < r; ++i) { dp[i][0] = dp[i - 1][0] + grid[i][0]; }
// for (int j = 1; j < c; ++j) { dp[0][j] = dp[0][j - 1] + grid[0][j]; }

// for (int i = 1; i < r; ++i) {
//     for (int j = 1; j < c; ++j) {
//         dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
//     }
// }

// std::cout << dp[r - 1][c - 1] << '\n';
