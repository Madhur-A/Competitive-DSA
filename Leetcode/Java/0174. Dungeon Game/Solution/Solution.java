



import java.util.*;

class Solution {
    public static final int inf = Integer.MIN_VALUE >> 1;

    public boolean canResque(int[][] dungeon, int health) { // apparently, for forward traversal, BS becomes essential
        int r = dungeon.length, c = dungeon[0].length;

        int currHealth = health + dungeon[0][0];
        if (currHealth <= 0) { return false; }

        int[][] dp = new int[r + 1][c + 1];

        dp[0][0] = currHealth;

        for (int i = 1; i < r; ++i) {
            int newValue = dp[i - 1][0] + dungeon[i][0];
            dp[i][0] = (newValue > 0) ? newValue : inf;
        }

        for (int j = 1; j < c; ++j) {
            int newValue = dp[0][j - 1] + dungeon[0][j];
            dp[0][j] = (newValue > 0) ? newValue : inf;
        }

        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                int  fromDown = dungeon[i][j] + dp[i - 1][j];
                int fromRight = dungeon[i][j] + dp[i][j - 1];
                if (fromDown > 0 || fromRight > 0) {
                    dp[i][j] = Math.max(fromDown, fromRight);
                } else {
                    dp[i][j] = inf; // effectively, blocking the path
                }
            }
        }

        return dp[r - 1][c - 1] > 0;
    }

    public int calculateMinimumHP(int[][] dungeon) {
        int r = dungeon.length, c = dungeon[0].length;
        int left = 1, right = 2001, mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (!canResque(dungeon, mid)) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}}; //{0,5},{-2,-3}};
        System.out.printf("res is %d\n", sol.calculateMinimumHP(dungeon));
    }
}
