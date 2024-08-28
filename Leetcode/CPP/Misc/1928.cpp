



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using element = std::tuple<int, int, int>;
public:
    std::unordered_map<int, std::vector<std::pair<int, int>>> g;
    std::vector<int> cost, itinerary;
    std::priority_queue<element, std::vector<element>, std::greater<element>> t; 
public:    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int const n = passingFees.size();
        int const dest = n - 1;
        cost.resize(n+1, INT_MAX);
        itinerary.resize(n+1, maxTime + 1);
        itinerary[0] = 0;
        cost[0] = passingFees[0];
        for(std::vector<int> const &edge: edges) {
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
        }
        t.push({passingFees[0], 0, 0}); // fee, time, node
        while(not t.empty()) {
            element const p = t.top(); t.pop();
            int const node = std::get<2>(p), time = std::get<1>(p), fees = std::get<0>(p);
            if(node == dest) { return cost[dest]; }
            if(time <= maxTime) {
                for(std::pair<int, int> const &child: g[node]) {
                    int const curr_fees = fees + passingFees[child.first], curr_time = time + child.second;
                    if(curr_time <= maxTime) {
                        if(curr_fees < cost[child.first]) {
                            cost[child.first] = curr_fees;
                            itinerary[child.first] = curr_time;
                            t.push({cost[child.first], itinerary[child.first], child.first});
                        } else {
                            if(curr_time < itinerary[child.first]) {
                                itinerary[child.first] = curr_time;
                                t.push({curr_fees, itinerary[child.first], child.first});        
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    int maxTime = 30;
    std::vector<std::vector<int>> edges = {{0,1,10},{1,2,10},{2,5,10},{0,3,1},{3,4,10},{4,5,15}};
    std::vector<int> passingFees = {5,1,2,20,20,3};

    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minCost(maxTime, edges, passingFees));


    return 0;    
}
