



import java.util.*;

class Solution {
    public int sigma, n;
    public int[][][] dp;

    public boolean dfs(int[] nums, int total, int count, int i) {
        final int a = total * n, b = sigma * count;
        if (count != 0 && n != count && a == b) { return true; }

        if (i == n) {
            return count != 0 && n != count && a == b;
        }
        if (dp[count][total][1] >= 0) { return true; }
        if (dp[count][total][0] >  2) { // visited enough
            return dp[count][total][1] >= 0;
        }

        boolean res = dfs(nums, total + nums[i], count + 1, i + 1) | dfs(nums, total, count, i + 1);

        dp[count][total][0] += 1; // visited counter
        dp[count][total][1] += (res) ? 1 : 0;

        return res;
    }

    public boolean splitArraySameAverage(int[] nums) {
        n = nums.length;
        if (n == 1) { return false; }
        for (int i = 0; i < n; sigma += nums[i], ++i);
        Arrays.sort(nums);
        dp = new int[n + 1][sigma + 1][2];
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < sigma + 1; ++j) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        boolean res = dfs(nums, 0, 0, 0);

        dp = new int[0][0][0]; // forcing GC

        return res;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
