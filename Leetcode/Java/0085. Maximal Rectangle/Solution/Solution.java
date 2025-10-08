



import java.util.*;

class Solution {
    // same as "0042. Trapping Rain Water" but with the caveat
    // that it would be go further than `n` since `h x w` is
    // done via `h x (w - 1)`; essential for the edge case where the total
    // width `n` is needed.
    public int getArea(int[] heights) {
        int n = heights.length, res = 0;
        Deque<Integer> s = new ArrayDeque<>();

        for (int i = 0; i < n + 1; ++i) {
            while (!s.isEmpty() && (i == n || heights[i] < heights[s.peek()])) {
                int h = heights[s.pop()];
                int w = s.isEmpty() ? i : i - s.peek() - 1;
                res = Math.max(res, h * w);
            }
            s.push(i);
        }

        return res;
    }

    public int maximalRectangle(char[][] grid) {
        int r = grid.length, c = grid[0].length;

        int[] heights = new int[c]; // heights
        int res = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                heights[j] = grid[i][j] == '1' ? (i == 0 ? 1 : heights[j] + 1) : 0;
            }
            res = Math.max(res, getArea(heights));
        }

        return res;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
