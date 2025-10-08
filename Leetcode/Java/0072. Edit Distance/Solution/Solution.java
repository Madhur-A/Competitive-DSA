



import java.util.*;

class Solution {
    public int tMin(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }

    // textbook definition of Levenshtein edit distance
    public int minDistance(String s, String t) {
        int r = s.length(), c = t.length();
        char[] sc = s.toCharArray(), tc = t.toCharArray();
        int[][] dp = new int[r + 1][c + 1];

        for (int i = 1; i < c + 1; ++i) { dp[0][i] = i; }
        for (int i = 1; i < r + 1; ++i) { dp[i][0] = i; }

        for (int i = 1; i < r + 1; ++i) {
            for (int j = 1; j < c + 1; ++j) {
                if (sc[i - 1] == tc[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + tMin(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
                }
            }
        }

        return dp[r][c];
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
