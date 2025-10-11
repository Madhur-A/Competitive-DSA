


import java.util.*;

class DepthFirst {
    public static final int inf = -(1 << 30);
    public int[][] dp;

    public int dfs(int[] nums, int index, int currSum, int target) {
        if (currSum  > target) { return inf; }
        if (currSum == target || index == nums.length) {
            return currSum == target ? 0 : inf;
        }

        if (dp[index][currSum] != -1) { return dp[index][currSum]; }

        int pick = 1 + dfs(nums, index + 1, nums[index] + currSum, target);
        int skip =     dfs(nums, index + 1,               currSum, target);

        return dp[index][currSum] = Math.max(pick, skip);
    }

    public int lengthOfLongestSubsequence(int[] nums, int target) {
        int n = nums.length;
        dp = new int[n][target + 1];
        for (int i = 0; i < n; ++i) { Arrays.fill(dp[i], -1); }

        int res = dfs(nums, 0, 0, target);
        return res < 0 ? -1 : res;
    }

    public int lengthOfLongestSubsequence(List<Integer> list, int target) {
        return lengthOfLongestSubsequence(list.stream().mapToInt(Integer::intValue).toArray(), target);
    }
}
