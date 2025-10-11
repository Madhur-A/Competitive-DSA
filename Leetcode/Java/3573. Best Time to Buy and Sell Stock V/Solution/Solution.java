



import java.util.*;

class Solution {
    public long maximumProfit(int[] prices, int k) {
        int n = prices.length;
        long[][][] dp = new long[n][k + 1][3]; // total of three eventualities are possible

        // a lot like previous questions, just with another decision-variable
        // of `going short`; hence ...[k + 1][3] instead of ...[k + 1][2]

        // the initial conditions could easily be set inside the main-
        // loop below, since all deciding conditions are causal

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < k + 1; ++j) {
                dp[0][j][1] = -prices[0]; // initial long
                dp[0][j][2] =  prices[0]; // initial short
                dp[i][j][0] = Math.max(dp[i - 1][j][0], Math.max(dp[i - 1][j][1] + prices[i], dp[i - 1][j][2] - prices[i])); // closing the position
                dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]); // going long
                dp[i][j][2] = Math.max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + prices[i]); // going short
            }
        }

        return dp[n - 1][k][0];
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
