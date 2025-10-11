



import java.util.*;

class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n][3][2];

        // the initial conditions could easily be set inside the main-
        // loop below, since all deciding conditions are causal

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < 3; ++j) {
                dp[0][j][1] = -prices[0]; // setting initial conditions
                dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][2][0];
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
