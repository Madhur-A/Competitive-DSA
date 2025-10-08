



import java.util.*;

class Solution {
    public boolean isScramble(String s, String t) {
        int n = s.length(), m = t.length();
        if (n   !=   m ) { return false; }
        if (s.equals(t)) { return true;  }

        boolean[][][] dp = new boolean[n][n][n + 1];

        char[] sc = s.toCharArray(), tc = t.toCharArray();


        // initial fill up
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][1] = (sc[i] == tc[j]);
            }
        }

        // full fill up
        for (int len = 2; len < n + 1; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                for (int j = 0; j < n - len + 1; ++j) {
                    for (int k = 1; k < len; ++k) {
                        boolean a = dp[i][j][k] && dp[i + k][j + k][len - k]; // no swap
                        boolean b = dp[i][j + len - k][k] && dp[i + k][j][len - k]; // cross-check
                        if (a || b) {
                            dp[i][j][len] = true;
                            break; // no need to go any further
                        }
                    }
                }
            }
        }


        return dp[0][0][n];
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
