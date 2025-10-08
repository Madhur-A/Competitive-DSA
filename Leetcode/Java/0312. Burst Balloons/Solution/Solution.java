



import java.util.*;

class Solution {
    public int maxCoins(int[] nums) {
        final int n = nums.length;
        int[][] dp = new int[n + 1][n + 1];

        for (int len = 1; len < n + 1; ++len) {
            for (int left = 0; left < n - len + 1; ++left) {
                int right = left + len - 1;
                for (int mid = left; mid < right + 1; ++mid) { // need to check every point in-between
                    int lv = left  < 1     ? 1 : nums[left - 1];
                    int rv = right > n - 2 ? 1 : nums[right + 1];
                    dp[left][right] = Math.max(dp[left][right],
                        (mid < 1 ? 0 : dp[left][mid - 1]) + dp[mid + 1][right] + lv * nums[mid] * rv);
                }
            }
        }

        return dp[0][n-1];
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
