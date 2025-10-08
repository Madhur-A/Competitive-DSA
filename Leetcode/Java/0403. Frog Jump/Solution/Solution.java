



import java.util.*;

class Solution {
    public boolean canCross(int[] stones) {
        int n = stones.length;
        boolean[][] dp = new boolean[n][n + 1]; // dp(i, j) = to index `i` with jump `j`
        dp[0][0] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int d = stones[i] - stones[j];
                if (d > -2 && d < n) {
                    dp[i][d] = dp[i][d] || dp[j][d - 1] || dp[j][d] || dp[j][d + 1];
                }
            }
        }

        boolean res = false;
        for (boolean r: dp[n - 1]) { res |= r; }

        return res;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
