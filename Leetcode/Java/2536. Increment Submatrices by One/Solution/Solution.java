



import java.util.*;

public class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int r = n + 2, c = n + 2;
        int[][] grid = new int[r][c];

        for (int[] query : queries) {
            int i = query[0], j = query[1], h = query[2], k = query[3];
            grid[i + 1][j + 1] += 1;
            grid[h + 2][k + 2] += 1;
            grid[h + 2][j + 1] -= 1;
            grid[i + 1][k + 2] -= 1;
        }

        int[][] ans = new int[n][n];

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                grid[i][j] = (grid[i][j] + grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1]);
                ans[i - 1][j - 1] = grid[i][j];
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        System.out.println("------------------DONE------------------");
    }
}
