



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
    inline static constexpr int const r = 1'000'000;
    inline static constexpr int const c = 1'000'000;
public:
    std::unordered_set<long> visited;
    std::unordered_set<long> walls;
public:
    bool is_valid(int x, int y) {
        return x >= 0 and y >= 0 and x < r and y < c and not visited.count(x*1L*c+y) and not walls.count(x*1L*c+y);
    }

    bool bfs(int si, int sj, int ti, int tj) {
        std::queue<long> t;
        t.push(si*1L*c + sj);
        visited.clear();
        while(not t.empty()) {
            long const p = t.front(); t.pop();
            int const i = p / c, j = p % c;
            if(visited.size() > 20555 or (i == ti and j == tj)) { return true; }
            if(not visited.count(p)) {
                visited.insert(p);
                for(direction const &dir: dirs) {
                    int const h = i + dir.first, k = j + dir.second;
                    if(is_valid(h, k)) {
                        t.push(h*1L*c + k);
                    }
                }
            }
        }
        return false;
    }

    bool dfs(int si, int sj, int ti, int tj) {
        if(is_valid(si, sj) and is_valid(ti, tj)) {
            if(visited.size() > 20555 or (si == ti and sj == tj)) { return true; }
            visited.insert(si*1L*c + sj);
            for(direction const &dir: dirs) {
                int const h = si + dir.first, k = sj + dir.second;
                if(is_valid(h, k)) {
                    if(dfs(h, k, ti, tj)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.empty()) { return true; }
        for(std::vector<int> const &block: blocked) {
            int const i = block[0], j = block[1];
            walls.insert(i*1L*c + j);
        }
        bool const from_source = bfs(source[0], source[1], target[0], target[1]);
        // visited.clear(); // this is for dfs
        bool const from_target = bfs(target[0], target[1], source[0], source[1]);

        return from_source and from_target;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> blocked = {{0,1},{1,0}};
    std::vector<int> source = {0,0}, target = {0,2};
    std::cout.setf(std::ios::boolalpha);
    std::cout << sol.isEscapePossible(blocked, source, target) << '\n';

    return 0;
}
