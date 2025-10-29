



import java.util.*;

class Solution {
    public static int mod = 1_000_000_007;

    public int numberOfPaths(int[][] grid, int k) {
        int r = grid.length, c = grid[0].length;

        int[][][] dp = new int[r][c][k];
        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int e = 0, s = 0; e < k; ++e) { // r[e]mainders
                    s = (e + grid[i][j]) % k;
                    dp[i][j][s] = (dp[i][j][s] + ((i > 0) ? dp[i - 1][j][e] : 0) + ((j > 0) ? dp[i][j - 1][e] : 0)) % mod;
                    // notice the modular addition propagate via causal value `e`, e.g. dp[i - 1][j][e] not dp[i - 1][j][s]
                    // the fact around which this is constructed.
                }
            }
        }

        return dp[r - 1][c - 1][0];
    }

    public static void main(String[] args) {
        System.out.println("------------------DONE------------------");
    }
}
