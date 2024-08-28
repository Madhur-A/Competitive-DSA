



#include <bits/stdc++.h>

using std::string;

class Solution {
public:
    int visited[10001];
public:
    int div = 0;
    std::string ans = "";
public:
    void dfs(int const& k, int const &node) {
        for(int i = 0; i < k; ++i) {
            int const num = node * 10 + i;
            if(not visited[num]) {
                visited[num] = true;
                dfs(k, num % div);
                ans += std::to_string(i);
            }
        }
    }
    
    string crackSafe(int n, int k) {    
        div = std::pow(10, n-1);
        memset(visited, 0, sizeof(visited));
        dfs(k, 0);
        ans += std::string(n-1, '0');
        return ans;
    }
};

int main() {
    int n = 1, k = 2;
    Solution sol;
    std::fprintf(stdout, "%s\n", sol.crackSafe(n, k).c_str());

    return 0;
}
