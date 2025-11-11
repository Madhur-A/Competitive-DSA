



import java.util.*;

class Solution {
    public static final int mod = 1_000_000_007;

    public int distinctSubseqII(String s) {
        int n = s.length(); char[] sc = s.toCharArray();
        int res = 0;
        int[] dp = new int[26];

        for (int i = 0; i < n; ++i) {
            int c = sc[i] - 'a', total = 0;
            for (int j = 0; j < 26; ++j) {
                total = (total + dp[j]) % mod;
            }
            dp[c] = (total + 1) % mod;
        }

        for (int i = 0; i < 26; ++i) { res = (res + dp[i]) % mod; }

        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        // System.out.printf("res is 7 == %d\n", sol.distinctSubseqII("abcdef"));
        System.out.printf("res is 6 == %d\n", sol.distinctSubseqII("aba"));
        // System.out.printf("res is 3 == %d\n", sol.distinctSubseqII("aaa"));
        // System.out.printf("res is 9 == %d\n", sol.distinctSubseqII("abaa"));

        System.out.println("------------------DONE------------------");
    }
}
