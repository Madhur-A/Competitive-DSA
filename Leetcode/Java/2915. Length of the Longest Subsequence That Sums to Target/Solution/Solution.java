



import java.util.*;

class Solution {
    public int lengthOfLongestSubsequence(int[] nums, int target) {
        int n = nums.length, total = Arrays.stream(nums).sum();

        if (total  < target) { return -1; }
        if (total == target) { return  n; }

        int[] dp = new int[target + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int subTarget = target; subTarget > nums[i] - 1; --subTarget) {
                if (dp[subTarget - nums[i]] != -1) {
                    dp[subTarget] = Math.max(dp[subTarget], dp[subTarget - nums[i]] + 1);
                }
            }
        }

        return dp[target];
    }

    public int lengthOfLongestSubsequence(List<Integer> list, int target) {
        return lengthOfLongestSubsequence(list.stream().mapToInt(Integer::intValue).toArray(), target);
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
