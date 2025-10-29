



import java.util.*;

class Solution {
    public static final int inf = Integer.MIN_VALUE >> 1;

    public int cherryPickup(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        // consider two collectors moving from (0,0) to (r-1, c-1), since this emulation
        // takes care of whether or not each collector has arrived on its respective
        // destination (as this becomes a problem in the contrary case, wherein one starts
        // from (0,0) and another from (r-1, c-1)).

        // then, for dp to hold good, the count of movements by both
        // must be equal i.e., `i + j == h + k`

        int[][][][] dp = new int[r][c][r][c]; // max iterations 6250000

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int h = 0; h < r; ++h) {
                    Arrays.fill(dp[i][j][h], inf);
                }
            }
        }

        dp[0][0][0][0] = grid[0][0];

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int h = 0; h < r; ++h) {
                    for (int k = 0; k < c; ++k) {
                        if (i + j != h + k) { continue; }
                        if (i == 0 && j == 0 && h == 0 && k == 0) { continue; }
                        if (grid[i][j] == -1 || grid[h][k] == -1) { continue; }

                        int prevOpt = inf;
                        if (i > 0 && h > 0) { prevOpt = Math.max(prevOpt, dp[i - 1][j][h - 1][k]); }
                        if (i > 0 && k > 0) { prevOpt = Math.max(prevOpt, dp[i - 1][j][h][k - 1]); }
                        if (j > 0 && h > 0) { prevOpt = Math.max(prevOpt, dp[i][j - 1][h - 1][k]); }
                        if (j > 0 && k > 0) { prevOpt = Math.max(prevOpt, dp[i][j - 1][h][k - 1]); }

                        if (prevOpt == inf) { continue; }

                        if (i != h || j != k) {
                            dp[i][j][h][k] = grid[i][j] + grid[h][k] + prevOpt;
                        } else {
                            dp[i][j][h][k] = grid[i][j] + prevOpt;
                        }
                    }
                }
            }
        }

        return Math.max(0, dp[r - 1][c - 1][r - 1][c - 1]);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] grid = new int[][]{{0,0,0},{-1,-1,0},{0,1,1}};

        System.out.printf("res is %d\n", sol.cherryPickup(grid));

        System.out.println("------------------DONE------------------");
    }
}
