



import java.util.*;

class Solution {
    public int minCut(String s) {
        int n = s.length();
        boolean[][] palindromes = new boolean[n][n];
        char[] sc = s.toCharArray();

        // !!! please note that though this passes all the tests;
        //     nevertheless, this program is not fullproof. for i've skipped
        //     setting the initial conditions beforehand and i'm setting them
        //     inside the loop below, which is technically incorrect, since
        //     the the optimality in palindrome-related conditions (in general
        //     and specifically here) is dependent also on the forward looking
        //     priori.

        // collect all palindromes
        for (int i = n - 1; i > -1; --i) {
            palindromes[i][i] = true;
            for (int j = i + 1; j < n; ++j) {
                if (sc[i] == sc[j] && (j - i < 3 || palindromes[i + 1][j - 1])) {
                    palindromes[i][j] = true; // extend the length
                }
            }
        }

        int[] dp = new int[n];

        for (int i = 1; i < n; ++i) {
            if (palindromes[0][i]) { dp[i] = 0; continue; }
            dp[i] = i; // worst case if each letter is taken only as palindrome
            for (int j = 1; j < i + 1; ++j) {
                if (palindromes[j][i] && dp[j - 1] + 1 < dp[i]) {
                    dp[i] = 1 + dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
