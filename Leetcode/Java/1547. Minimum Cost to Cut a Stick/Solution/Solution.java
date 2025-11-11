



import java.util.*;

class Solution {
    public int minCost(int n, int[] cuts) {
        int[] newCuts = new int[cuts.length + 2];
        newCuts[0] = 0; newCuts[cuts.length + 1] = n;
        for (int i = 1; i < cuts.length + 1; ++i) { newCuts[i] = cuts[i - 1]; }
        int L = newCuts.length;

        int[][] dp = new int[L][L];
        Arrays.sort(newCuts);

        for (int len = 2; len < L; ++len) {
            for (int left = 0; left < L - len; ++left) {
                int right = left + len;
                dp[left][right] = 1 << 30;
                for (int mid = left; mid < right; ++mid) {
                    dp[left][right] = Math.min(dp[left][right], dp[left][mid] + dp[mid][right] + (newCuts[right] - newCuts[left]));
                }
            }
        }

        return dp[0][L - 1];
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
