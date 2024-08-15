




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    bool dfs(vector<int>& nums, int start) {
        int const n = nums.size();
        std::vector<bool> visited(n);

        std::function<bool(int)> rx = [&](int i) {
            if(i >= n or i < 0 or visited[i]) { return false; }
            if(visited[i] or (nums[i] == 0))  { return true;  }
            if(not visited[i]) {
                visited[i] = true;
                return rx(i - nums[i]) or rx(i + nums[i]);
            }
            return false;
        };
        return rx(start);
    }

    bool bfs(vector<int>& nums, int start) {
        int const n = nums.size();
        std::vector<bool> visited(n);
        std::queue<int> t;
        t.push(start);
        while(not t.empty()) {
            int const i = t.front(); t.pop();
            if(nums[i] == 0) { return true; }
            if(not visited[i]) {
                visited[i] = true;
                if(i + nums[i] <  n) { t.push(i + nums[i]); }
                if(i - nums[i] > -1) { t.push(i - nums[i]); }
            }
        }
        return false;
    }

    bool canReach(vector<int>& nums, int start) {
//        return dfs(nums, start);
        return bfs(nums, start);
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {4,2,3,0,3,1,2};
    int start = 5;
    std::cout.setf(std::ios::boolalpha);
    std::cout << sol.canReach(nums, start) << '\n';


    return 0;
}

