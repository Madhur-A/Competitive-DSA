



import java.util.*;

class Solution {
    public int minPathSum(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        int[][] dp = new int[r][c];

        dp[0][0] = grid[0][0];

        // fill the first row (for grids having a single row only)
        for (int j = 1; j < c; ++j) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }

        for (int i = 1; i < r; ++i) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
            for (int j = 1; j < c; ++j) {
                dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[r - 1][c - 1];
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
