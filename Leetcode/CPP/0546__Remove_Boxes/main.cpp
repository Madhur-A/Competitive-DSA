



#include <bits/stdc++.h>
#include <ranges>

using std::vector;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int const n = boxes.size();        
        int const max_possible = std::max_element(boxes.begin(), boxes.end())[0];

        std::vector<int> freq(max_possible + 1), indices(n);

        for(int i = 0; i < n; ++i) {
            freq[boxes[i]] += 1;
            indices[i] = freq[boxes[i]];
        }

        std::copy(indices.begin(), indices.end(), std::ostream_iterator<int>(std::cout, " ")); std::putc('\n', stdout);

        return 5;
    }
};

/*
 * Q: How many decisions could you take?
 * A: How many situation could arise?
 *
 * Since we're fixing frequencies from left-to-right, then
*/

int main() {
    Solution sol;
    std::vector<int> boxes = {1,3,2,2,2,3,4,3,1};
    std::fprintf(stdout, "%d\n", sol.removeBoxes(boxes));


    return 0;
}
