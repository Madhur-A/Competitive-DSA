



import java.util.*;

class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        int[][] dp = new int[r][c];

        dp[0][0] = grid[0][0] == 0 ? 1 : 0;

        // fill the first row
        for (int j = 1; j < c; ++j) {
            dp[0][j] = grid[0][j] == 1 ? 0 : dp[0][j - 1];
        }

        // fill the first column
        for (int i = 1; i < r; ++i) {
            dp[i][0] = grid[i][0] == 1 ? 0 : dp[i - 1][0];
        }

        // fill the rest
        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                if (grid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[r - 1][c - 1];
    }

    public static void main(String[] args) {
    }
}
