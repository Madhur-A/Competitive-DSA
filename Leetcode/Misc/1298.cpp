



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    std::queue<int> t;
    std::unordered_set<int> have, boxes; //have_keys, have_boxes
    std::unordered_set<int> seen;
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        for(int const &box: initialBoxes) { 
            t.push(box);
            boxes.insert(box); 
        }
        int ans = 0;
        
        while(not t.empty()) {
            int const box = t.front(); t.pop();
            if(boxes.count(box) and (have.count(box) or status[box]) and not seen.count(box)) {
                ans += candies[box];
                seen.insert(box);
                for(int const &k: keys[box]) { have.insert(k); t.push(k); }
                for(int const &new_box: containedBoxes[box]) {
                    boxes.insert(new_box);
                    t.push(new_box);
                }
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> status = {1,0,1,0};
    std::vector<int> candies = {7,5,4,100};
    std::vector<std::vector<int>> keys = {{},{},{1},{}};
    std::vector<std::vector<int>> containedBoxes = {{1,2},{3},{},{}};
    std::vector<int> initialBoxes = {0};

    Solution sol;
    std::fprintf(stdout, "%d\n", sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes));


    
    return 0;
}
