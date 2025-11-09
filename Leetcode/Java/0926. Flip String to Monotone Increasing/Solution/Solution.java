



import java.util.*;

class Solution {
    // 1. two pass precomputed arrays (okay)
    public int minFlipsMonoIncr(String s) {
        int n = s.length(); char[] sc = s.toCharArray();
        // -- using prefix and suffix arrays --
        // consider splitting the string at some index `i`, then
        // the mininum cost would be the cost of making all of
        // the elements at the left `i` equal to 0 and likewise
        // all the elements at the right of `i` to 1.

        // consider `int[] prefix` to be the cost of making all characters left of `i` 0.
        int[] prefix = new int[n], suffix = new int[n];
        prefix[0] = sc[0] == '0' ? 0 : 1;
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + (sc[i] == '0' ? 0 : 1);
        }

        // and similarly for `suffix`
        suffix[n - 1] = sc[n - 1] == '1' ? 0 : 1;
        for (int i = n - 2; i > -1; --i) {
            suffix[i] = suffix[i + 1] + (sc[i] == '1' ? 0 : 1);
        }

        int res = Math.min(prefix[n - 1], suffix[0]); // to turn all 0's into 1's and vice versa
        for (int i = 1; i < n; ++i) {
            res = Math.min(res, prefix[i - 1] + suffix[i]);
        }

        return res;
    }

    // 2. typical buDP (worst, due to branch-unpredictibility for compiler)
    public int minFlipsMonoIncr(String s) {
        int n = s.length(); char[] sc = s.toCharArray();
        int[][] dp = new int[n][2];
        dp[0][0] = sc[0] == '0' ? 0 : 1;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0] + (sc[i] == '1' ? 1 : 0);
            dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][1]) + (sc[i] == '0' ? 1 : 0);
        }

        return Math.min(dp[n - 1][0], dp[n - 1][1]);
    }

    // 3. buDP optimized (better than all above)
    public int minFlipsMonoIncr(String s) {
        int n = s.length(); char[] sc = s.toCharArray();
        int rei = 0, ich = 0;
        for (int i = 0; i < n; ++i) {
            int newRei = rei + (sc[i] - '0');
            int newIch = Math.min(rei, ich) + (1 - (sc[i] - '0'));
            rei = newRei; ich = newIch;
        }

        return Math.min(rei, ich);
    }

    public static void main(String[] args) {
        // Solution sol = new Solution();
        System.out.println("------------------DONE------------------");
    }
}
