



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int const n = machines.size();
        long total = std::reduce(machines.begin(), machines.end(), 0L);	  
        if((total % n) != 0) { return -1; }
        int const avg = total/n;
        int rem = 0, curr = 0, res = 0;
        for(int const &machine: machines) {
            rem   = machine - avg;
            curr += rem;
			
            res   = std::max(res, std::max(std::abs(curr), rem)); 
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> machines = {1,0,5};
    
    std::fprintf(stdout, "%d\n", sol.findMinMoves(machines));


    return 0;
}
