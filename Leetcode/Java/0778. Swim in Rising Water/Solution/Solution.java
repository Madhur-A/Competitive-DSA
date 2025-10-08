



import java.util.*;

class Solution {
    public static int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0}};

    public boolean isValid(int r, int c, int i, int j) {
        return i >= 0 && j >= 0 && i < r && j < c;
    }

    public boolean traverseDFS(int[][] grid, boolean[] seen, int initialTime, int i, int j) {
        int r = grid.length, c = grid[0].length;
        if (i == r - 1 && j == c - 1) { return true; }
        for (int[] dir: dirs) {
            int h = dir[0] + i, k = dir[1] + j;
            if (isValid(r, c, h, k) && !seen[h*c + k] && initialTime >= grid[h][k]) {
                seen[h*c + k] = true;
                if (traverseDFS(grid, seen, initialTime, h, k)) {
                    return true;
                }
            }
        }

        return false;
    }

    public boolean traverseBFS(int[][] grid, int initialTime) {
        int r = grid.length, c = grid[0].length;
        int k = 10000; // removes the necessity for using `Pair`
        if (initialTime < grid[0][0]) { return false; }
        ArrayDeque<Integer> t = new ArrayDeque<>(); // {time, position}
        t.offerFirst(initialTime * k);
        boolean[] seen = new boolean[r*c];

        while (!t.isEmpty()) {
            int curr = t.pollLast();
            int time = curr / k, position = curr % k;
            int i = position / c, j = position % c;
            if (i == r - 1 && j == c - 1) { return true; }

            if (!seen[position]) {
                seen[position] = true;
                for (int[] dir: dirs) {
                    int x = dir[0] + i, y = dir[1] + j;
                    if (isValid(r, c, x, y) && time >= grid[x][y]) {
                        t.offerFirst(time * k + (x*c + y));
                    }
                }
            }
        }
        return false;
    }

    public int swimInWater(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        int left = 0, right = r * (c + 1), mid = 0;
        boolean[] seen = new boolean[r*c];

        while (left < right) {
            mid = left + ((right - left) >> 1);
            // if (!traverseBFS(grid, mid)) { left  = mid + 1; } else { right = mid;}
            if (mid >= grid[0][0]) { // predicate for a successful dfs
                Arrays.fill(seen, false);
                seen[0] = true;
                if (!traverseDFS(grid, seen, mid, 0, 0)) {
                    left  = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                left  = mid + 1;
            }
        }

        return left;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
