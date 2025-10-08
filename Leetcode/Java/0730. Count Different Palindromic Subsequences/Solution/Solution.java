



class Solution {
    public static final int mod = 1_000_000_007;

    public int countPalindromicSubsequences(String s) {
        int n = s.length();
        char[] sc = s.toCharArray();

        int[][][] dp = new int[n][n][4]; // alphabet has only four-letters

        for (int i = 0; i < n; ++i) {
            int k = sc[i] - 'a';
            dp[i][i][k] = 1;
        }


        for (int len = 2; len < n + 1; ++len) {
            for (int left = 0; left < n + 1 - len; ++left) {
                int right = left + len - 1;
                for (int i = 0; i < 4; ++i) {
                    char c = (char)('a' + i);
                    if (sc[left] == c && sc[right] == c) {
                        dp[left][right][i] = 2;
                        // count the rest in-between
                        for (int j = 0; j < 4; ++j) {
                            dp[left][right][i] += dp[left + 1][right - 1][j];
                            dp[left][right][i] %= mod;
                        }
                    } else if (sc[left] == c && sc[right] != c) {
                        dp[left][right][i] = dp[left][right - 1][i];
                    } else if (sc[right] == c && sc[left] != c) {
                        dp[left][right][i] = dp[left + 1][right][i];
                    } else {
                        dp[left][right][i] = dp[left + 1][right - 1][i];
                    }
                }
            }
        }

        // all subsequence starting from 0 and ending at n - 1, of any length;
        long res = 0L;
        for (int i = 0; i < 4; ++i) {
            res += dp[0][n - 1][i];
            res %= mod;
        }


        return (int)res;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
