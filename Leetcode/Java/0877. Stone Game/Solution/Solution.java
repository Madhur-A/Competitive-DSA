



import java.util.*;

class Solution {
    public boolean stoneGame(int[] piles) {
        // for the sake of completeness; otherwise the answer would
        // always be `true`.
        int n = piles.length;
        int[][] dp = new int[n][n];

        for (int i = 0; i < n; ++i) { dp[i][i] = piles[i]; }

        for (int len = 2; len < n + 1; ++len) {
            for (int left = 0; left < n - len + 1; ++left) {
                int right = left + len - 1;
                dp[left][right] = Math.max(piles[left] - dp[left + 1][right], piles[right] - dp[left][right - 1]);
            }
        }

        return dp[0][n - 1] > 0;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
