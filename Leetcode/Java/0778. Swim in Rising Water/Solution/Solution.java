



import java.util.*;

class Solution {
    public static int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0}};

    public boolean isValid(int r, int c, int i, int j) {
        return i >= 0 && j >= 0 && i < r && j < c;
    }

    public boolean canCross(int[][] grid, boolean[] seen, int thres, int i, int j) {
        int r = grid.length, c = grid[0].length;
        if (i == r - 1 && j == c - 1) { return true; }

        for(int[] dir: dirs) {
            int h = dir[0] + i, k = dir[1] + j;
            if (isValid(r, c, h, k) && !seen[h*c + k] && Math.abs(grid[h][k] - grid[i][j]) <= thres) {
                seen[h*c + k] = true;
                if (canCross(grid, seen, thres, h, k)) {
                    return true;
                }
            }
        }

        return false;
    }

    public int minimumEffortPath(int[][] grid) {
        int r = grid.length, c = grid[0].length;

        int left = 0, right = 1_000_000, mid = 0;
        boolean[] seen = new boolean[r*c];

        while (left < right) {
            mid = left + ((right - left) >> 1);
            Arrays.fill(seen, false);
            seen[0] = true;
            if (!canCross(grid, seen, mid, 0, 0)) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
