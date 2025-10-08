



import java.util.*;

class Solution {
    public int numDistinct(String s, String t) {
        int r = s.length(), c = t.length();
        int[][] dp = new int[r + 1][c + 1];

        for (int i = 0; i < r + 1; ++i) { dp[i][0] = 1; }

        char[] sc = s.toCharArray(), tc = t.toCharArray();

        for (int i = 1; i < r + 1; ++i) {
            for (int j = 1; j < c + 1; ++j) {
                boolean previousValid = sc[i - 1] == tc[j - 1];
                dp[i][j] = dp[i - 1][j] + (previousValid ? dp[i - 1][j - 1] : 0);
            }
        }

        return dp[r][c];
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
