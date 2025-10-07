



import java.util.*;

class Solution {
    public int deleteAndEarn(int[] nums) {
        int n = nums.length, len = 10001, highest = 0;
        int[] f = new int[len];

        for (int i = 0; i < n; ++i) {
            f[nums[i]] += nums[i];
            highest = Math.max(highest, nums[i]);
        }

        int[] dp = new int[highest + 2];
        dp[0] = f[0];

        for (int i = 1; i < highest + 1; ++i) {
            dp[i] = Math.max(dp[i - 1], i > 1 ? dp[i - 2] + f[i] : f[i]);
        }

        return dp[highest];
    }

	public static void main(String[] args) {}
}
