



import java.util.*;

class Solution {
    public static final int mod = 1_000_000_007;

    public int numRollsToTarget(int n, int k, int target) {
        // number of ways to reach target using one face only once;
        // not exactly, but some semblance could be seen in "0377. Combination Sum IV"

        // the tricky part is that usage of all dice to construct the target,
        // e.g., if `target` is `2` and `n` is `3` then it would be invalid to
        // count number of ways of a single dice (considering `k > 1` of course)
        // which could indeed yield as a possible (but incorrect) way.

        // thus and thereby,
        if (target < n || target > n*k) { return 0; }

        int[][] dp = new int[n + 1][target + 1];
        dp[0][0] = 1;

        for (int i = 1; i < n + 1; ++i) {
            for (int face = 1; face < k + 1; ++face) {
                for (int subTarget = face; subTarget < Math.min(i*k, target) + 1; ++subTarget) {
                    dp[i][subTarget] = (int)(((long)dp[i][subTarget] + dp[i - 1][subTarget - face]) % mod);
                }
            }
        }

        return dp[n][target];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        assert sol.numRollsToTarget(1, 6, 3) == 1;
        assert sol.numRollsToTarget(2, 6, 7) == 6;

        System.out.println("------------------DONE------------------");
    }
}
