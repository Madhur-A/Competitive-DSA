




#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int b_find(std::vector<std::vector<int>> const &nums, int target) { // >= target
        int left = 0, right = nums.size()-1, mid = 0;
        // int terminal = INT_MIN;
        while(left < right) {
            mid = left + ((right - left) >> 1);
            if(nums[mid][1] > target) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int const n = rooms.size(), m = queries.size();
	std::vector<int> ans(m, -1);
	for(int i = 0; i < m; ++i) { queries[i].push_back(i); }

        std::ranges::sort(rooms, [&](std::vector<int> const &a, std::vector<int> const &b){
            return a[1] > b[1];
        });

        std::ranges::sort(queries, [&](std::vector<int> const &a, std::vector<int> const &b){
            return a[1] > b[1];
        });	
        
        std::ranges::for_each(rooms, [&](std::vector<int> const &room){
            std::fprintf(stdout, "[%d,%d] ", room[0], room[1]);
        });
        std::putc('\n', stdout);
        
        for(std::vector<int> const &query: queries) {
            int const preferred = query[0], min_size = query[1], index = query[2];
            int const found = b_find(rooms, min_size);
            std::fprintf(stdout, "(%2d,%2d) is %d\n", preferred, min_size, found);
        }
        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> rooms = {{23,22},{6,20},{15,6},{22,19},{2,10},{21,4},{10,18},{16,1},{12,7},{5,22}};
    std::vector<std::vector<int>> queries = {{12,5},{15,15},{21,6},{15,1},{23,4},{15,11},{1,24},{3,19},{25,8},{18,6}};
    Solution sol;
    std::vector<int> ans = sol.closestRoom(rooms, queries);
    std::ranges::copy(ans, std::ostream_iterator<int>(std::cout, " ")); std::putc('\n', stdout);
    


    return 0;
}
