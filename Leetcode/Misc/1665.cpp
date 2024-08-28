



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    bool condition(vector<vector<int>>& tasks, int given) {
        int const n = tasks.size();
        for(int i = 0; i < n; ++i) {
            if(given >= tasks[n-1-i][1]) {
                given = given - tasks[n-1-i][0];
            } else {
                return false;
            }
        }
        return true;
    }
    
    int minimumEffort(vector<vector<int>>& tasks) {
        std::ranges::sort(tasks, [&](std::vector<int> const &a, std::vector<int> const &b){
            return a[1]-a[0] < b[1]-b[0];
        });
        int left = 1, right = 1000000000, mid = 0;
        while(left < right) {
            mid = left + ((right - left) >> 1);
            if(not condition(tasks, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    std::vector<std::vector<int>> tasks = {{1,2},{2,4},{4,8}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minimumEffort(tasks));


    return 0;
}
