



#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    static int zc(int num) { // zero count
        int res = 0, ldg = num % 10;
        while(ldg == 0) {
	    res += 1;
            num /= 10;
	    ldg  = num % 10;
        }
        return res;
    }
    
    int shorten(int num) {
        int last_digit = num % 10, pwr = 0, r = 3;
        while(last_digit == 0) {
            pwr += 1;
            num /= 10;
	    last_digit = num % 10;
        }
	int res = 0, d = 0;
	while(num and r--) {
	    res += last_digit * std::pow(10, d++);
	    num = num / 10;
	    last_digit = num % 10;
	}
        return res * std::pow(10, pwr);
    }
    
    int count_ones(vector<vector<int>>& grid, int const &x, int const &y) {
        // std::fprintf(stdout, "for x: %d, y: %d\n", x, y);
        int const r = grid.size(),  c =  grid[0].size();
        long long upper_half = 1, uh = x-1;
        while(uh >= 0) { upper_half *= grid[uh--][y]; upper_half = shorten(upper_half); }
        long long lower_half = 1, lh = x+1;
        while(lh  < r) { lower_half *= grid[lh++][y]; lower_half = shorten(lower_half); }
        
        // std::fprintf(stdout, "upperhalf %d; lowerhalf %d\n", upper_half, lower_half);
        
        long long left = 1, right = 1, l = y-1, d = y+1;
        while(l >= 0) { left  *= grid[x][l--]; left  = shorten(left);  }
        while(d  < c) { right *= grid[x][d++]; right = shorten(right); }
        
        // std::fprintf(stdout, "left %d; right %d\n", left, right);
        int const u = zc(upper_half), b = zc(lower_half), g = zc(left), t = zc(right);
        
        return std::max(zc(u * grid[x][y] * std::max(g, t)), zc(b * grid[x][y] * std::max(g, t)));
    }
    
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int const r = grid.size(),  c =  grid[0].size();
        std::vector<std::vector<int>> five(r, std::vector<int>(c));
        
        for(int i = 0; i <  r; ++i) {
            for(int j = 0; j < c; ++j) {
                int const num = grid[i][j];
                if((num % 2) == 0 or (num % 5) == 0) {
                    five[i][j] = 1;
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i <  r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(five[i][j]) {
                    ans = std::max(ans, count_ones(grid, i, j));
                }
            }
        }
        
        return ans;
        
    }
};

int main(int argc, char* argv[]) {
    int const num = argc == 1 ? 32902390 : std::stoi(argv[1]);
    std::fprintf(stdout, "shorten(%d) = %d\n", num, Solution::zc(num));
    

    return 0;
}
