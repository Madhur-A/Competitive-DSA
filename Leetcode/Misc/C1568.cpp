



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    using direction = std::pair<int, int>;
public:
    inline static constexpr direction const dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    std::vector<std::vector<bool>> visited;
    std::queue<std::pair<int, int>> t;
public:
    int count_islands_dfs(vector<vector<int>>& grid, int const &x, int const &y) {
	int const r = grid.size(), c = grid[0].size();
	if(x >= 0 and y >= 0 and x < r and y < c and not visited[x][y]) {
	    visited[x][y] = true;
	    int res = grid[x][y];
	    for(direction const &dir: dirs) {
		int const h = dir.first + x, k = dir.second + y;
		if(h >= 0 and k >= 0 and h < r and k < c and grid[h][k] and not visited[h][k]) {
		    res = res & count_islands_dfs(grid, h, k);
		}
	    }
	    visited[x][y] = false;
	    return res;
	}
	return false;
    }
    
    int count_islands_bfs(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        visited.clear();
        visited.resize(r, std::vector<bool>(c));
        int islands = 0;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] and not visited[i][j]) {
                    t.push({i, j});
                    islands += 1;
                    while(not t.empty()) {
                        std::pair<int, int> const p = t.front(); t.pop();
                        int const x = p.first, y = p.second;
                        if(not visited[x][y]) {
                            visited[x][y] = true;
                            for(direction const &dir: dirs) {
                                int const h = dir.first + x, k = dir.second + y;
                                if(h >= 0 and k >= 0 and h < r and k < c and not visited[h][k] and grid[h][k]) {
                                    t.push({h, k});
                                }
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
    
    int minDays(vector<vector<int>>& grid) {
        int const r = grid.size(), c = grid[0].size();
        int res = count_islands_bfs(grid);
        if(res == 0 or res > 1) { return 0; }
        res = 0;
	visited.clear();
	visited.resize(r, std::vector<bool>(c));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    res += count_islands_dfs(grid, 0, 0);
                    if(res > 1) { return 1; }
                    grid[i][j] = 1;
                }
            }
        }
            
        return (res == 0) ? 1 : 2;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{0,1,1,0},{0,1,1,0},{0,0,0,0}};
    Solution sol;
    std::fprintf(stdout, "%d\n", sol.minDays(grid));


    return 0;
}


class sox {
public:
    vector<pair<int,int>> moves = {{0,-1}, {-1,0}, {0, 1}, {1, 0}}; // left, up, right, down
    // this tarjan code is copied from - https:// www.geeksforgeeks.org/problems/articulation-point-1/1

    bool areCoordinatesValid(int row, int col, int rows, int cols) {
	return (row >= 0 and col >= 0 and row < rows and col < cols);
    }

    void dfsToMarkVisited(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid) {
        int const rows = grid.size(), cols = grid[0].size();
        visited[row][col] = 1;
        for(auto move: moves) { // calculating neighbour coordinates using moves array
            int nbrRow = row + move.first, nbrCol = col + move.second;
            if(not areCoordinatesValid(nbrRow, nbrCol, rows, cols) or grid[nbrRow][nbrCol] == 0) {
                // if the nrighbour cooridinates are invalid/ out of bounds continue to next move/ neighbour
                continue;
            }
            if(not visited[nbrRow][nbrCol]) { dfsToMarkVisited(nbrRow, nbrCol, visited, grid); }
        }
    }

    bool tarjan(int row, int col, int parentRow, int parentCol, int currDfsStep, vector<vector<int>>& dfsStep, vector<vector<int>>& lowestStepToGraph, vector<vector<int>>& grid) {
	int const rows = grid.size(), cols = grid[0].size();
        dfsStep[row][col] = currDfsStep;
        lowestStepToGraph[row][col] = currDfsStep;
        // this counter is only needed for starting node
        int numberOfDisconnectedChild = 0;

        // visiting neighbours
        for(auto move: moves) {
            // preparing potential neighbour row and neighbour col
            int nbrRow = row + move.first, nbrCol = col + move.second;

            if(! areCoordinatesValid(nbrRow, nbrCol, rows, cols) or grid[nbrRow][nbrCol] == 0) {
                continue; // if out of bounds coordinates, continue to next move/ nbr
            }

            if(dfsStep[nbrRow][nbrCol] == -1) { // neighbour is unvisited
                numberOfDisconnectedChild += 1;
                bool apInSubgraph = tarjan(nbrRow, nbrCol, row, col, currDfsStep+1, dfsStep, lowestStepToGraph, grid);
                // this condition does not work for starting node
                if(apInSubgraph) { // if there was an access point in the garph later
                    return true;
                }
                // this condition does not work for starting node
                if((lowestStepToGraph[nbrRow][nbrCol] >= dfsStep[row][col]) && (currDfsStep != 0)) {
                    // it means neighbour is not connected to any cell via which it can reach already
		    // traveresed graph, hence removng row, col will cause graph to be disconnected
                    // cout<<"tarjan true for curr, nbr "<<row<<","<<col<<'-'<<nbrRow<<','<<nbrCol<<' '<<lowestStepToGraph[row][col]<<'-'<<lowestStepToGraph[nbrRow][nbrCol]<<endl;
                    return true;
                }
                // if the neighbour was connected to any cell via which it can reach to previously traversed graph it
		// means current cell is also connected to that cell via which it can also reach to previously traversed graph
                lowestStepToGraph[row][col] = min(lowestStepToGraph[nbrRow][nbrCol], lowestStepToGraph[row][col]);
            } else { // neighbour was already visited            
                // check for parent also (if needed or not)
                // cout<<"checking from visited neigghbours "<<nbrRow<<','<<nbrCol<<' '<<dfsStep[nbrRow][nbrCol]<<' '<<lowestStepToGraph[row][col]<<endl;
                lowestStepToGraph[row][col] = min(dfsStep[nbrRow][nbrCol], lowestStepToGraph[row][col]);
            }
        }
        // only for starting node
        if(currDfsStep == 0 && numberOfDisconnectedChild > 1) {
            return true;
        }
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        // there can only be 3 possible answers - 0, 1 and 2.
	// refer
	//https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/solutions/1293931/simplest-explanation-with-diagram-articulation-point-tarjan-algo-faster-than-100/

        int rows = grid.size(), cols = grid[0].size();
        int islandCells = 0, waterCells = 0;
        // we need coordinates of any land cell as starting point of tarjan
        int rowForTarjan, colForTarjan;
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                if(grid[row][col] == 1) {
                    islandCells += 1;
                    rowForTarjan = row;
                    colForTarjan = col;
                }
                else{
                    waterCells += 1;
                }
            }
        }

        // if there is no island cell then answer is 0 (all water is also considered disconnected)
        // if there are already disconnected islands then also ans is 0 but we will check that case later
        if(islandCells == 0) { return 0; }
        if(islandCells == 1) { return 1; }
        if(waterCells  == 0) { return 2; }

        // if there are disconnected islands already (more than 1 component in graph)
        // intuition- for any island cell we run a dfs, after running dfs if we stil find any unvisited island cell we know the graph is already is already disconnected
        bool dfsRan = false;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                if(grid[row][col] == 1 && not visited[row][col]) {
                    // we found an island cell
                    if(dfsRan) {
                        // we already ran a dfs, it means the graph/islands is already disconnected
                        return 0;
                    } else { // we run a dfs from this node                    
                        dfsToMarkVisited(row, col, visited, grid);
                        dfsRan = true;
                    }
                }
            }
        }

        // if there is any articulation point in graph then we can disconnect the graph by removing that island
        // stores the dfs step/count at which the node was visited, also used to track visited cells
        vector<vector<int>> dfsStep(rows, vector<int>(cols, -1));
        // stores the (min) dfs step of all the neighbours via which this node can be connected to previously traversed graph
        vector<vector<int>> lowestStepToGraph(rows, vector<int>(cols, -1));
        bool articulationPointPresent = false;
        if(tarjan(rowForTarjan, colForTarjan, -1, -1, 0, dfsStep, lowestStepToGraph, grid)) {            
            return 1; // it means there is an articulation point in the graph
        } else {            
            return 2; // in everything else do not match, there will always be a corner cell which can be disconnected by removing the two adjacent islandCells
        }
    }
};
