



import java.util.*;

class Solution {
    public int minSwap(int[] p, int[] q) {
        int n = p.length;
        int[][] dp = new int[n][2];
        dp[0][1] = 1;

        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i][1] = 1 << 20;
            if (p[i] > p[i - 1] && q[i] > q[i - 1]) {
                dp[i][0] = Math.min(dp[i][0], dp[i - 1][0]);
                dp[i][1] = Math.min(dp[i][1], dp[i - 1][1] + 1);
            }
            if (p[i] > q[i - 1] && q[i] > p[i - 1]) { // forcing swap; hence ...
                dp[i][0] = Math.min(dp[i][0], dp[i - 1][1]); // cross ...
                dp[i][1] = Math.min(dp[i][1], dp[i - 1][0] + 1); // matchings.
            }
        }

        return Math.min(dp[n - 1][0], dp[n - 1][1]);
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
