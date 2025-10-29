



import java.util.*;

class Solution {
    public static final int inf = -1;

    public int cherryPickup(int[][] grid) {
        int r = grid.length, c = grid[0].length, res = 0;
        int[][][] dp = new int[r][c][c];

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                Arrays.fill(dp[i][j], inf);
            }
        }

        dp[0][0][c - 1] = grid[0][0] + grid[0][c - 1];

        for (int i = 1; i < r; ++i) { // since both robots would be in same row
            for (int j = 0; j < c; ++j) {
                for (int k = 0; k < c; ++k) {

                    int prevOpt = -1;

                    for (int x = -1; x < 2; ++x) {
                        for (int y = -1; y < 2; ++y) {
                            int u = j + x, v = k + y;
                            if (u >= 0 && v >= 0 && u < c && v < c) {
                                prevOpt = Math.max(prevOpt, dp[i - 1][u][v]);
                            }
                        }
                    }

                    if (prevOpt == inf) { continue; }

                    if (j != k) {
                        dp[i][j][k] = grid[i][j] + grid[i][k] + prevOpt;
                    } else {
                        dp[i][j][k] = grid[i][j] + prevOpt;
                    }
                    res = Math.max(res, dp[i][j][k]);
                }
            }
        }


        return res;
    }

    public static void main(String[] args) {
        System.out.println("------------------DONE------------------");
    }
}
