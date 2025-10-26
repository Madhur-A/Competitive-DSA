



import java.util.*;

class Solution {
    public static final int mod = 1_000_000_007;

    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        int[][] dp = new int[n + 1][minProfit + 1];
        dp[0][0] = 1;

        long res = 0;

        for (int i = 0; i < profit.length; ++i) {
            for (int subTarget = n; subTarget > group[i] - 1; --subTarget) {
                for (int j = minProfit; j > -1; --j) {
                    int currProfit = Math.min(j + profit[i], minProfit);
                    dp[subTarget][currProfit] += dp[subTarget - group[i]][j];
                    dp[subTarget][currProfit] %= mod;
                }
            }
        }

        for (int i = 0; i < n + 1; ++i) {
            res += dp[i][minProfit];
            res %= mod;
        }

        return (int)res;
    }

    public static void main(String[] args) {
        System.out.println("------------------DONE------------------");
    }
}
