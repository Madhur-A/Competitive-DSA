



import java.util.*;

class Solution {
    public int removeBoxes(int[] boxes) {
        int n = boxes.length;
        int[][][] dp = new int[n][n][n];

        for (int len = 1; len < n + 1; ++len) {
            for (int left = 0; left < n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k > -1; --k) {
                    int curr = (k + 1) * (k + 1);
                    if (left < right && dp[left + 1][right][0] > 0) {
                        curr += dp[left + 1][right][0];
                    }
                    for (int mid = left + 1; mid < right + 1; ++mid) {
                        if (boxes[mid] == boxes[left]) {
                            curr = Math.max(curr, dp[left + 1][mid - 1][0] + dp[mid][right][k + 1]);
                        }
                    }

                    dp[left][right][k] = curr;
                }
            }
        }

        return dp[0][n - 1][0];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.printf("res [23 == %d]\n", sol.removeBoxes(new int[]{1,3,2,2,2,3,4,3,1}));
        System.out.println("------------------DONE------------------");
    }
}
