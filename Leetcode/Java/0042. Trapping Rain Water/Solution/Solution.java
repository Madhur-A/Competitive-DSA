



import java.util.*;

class Solution {
    public int trap(int[] heights) {
        int n = heights.length, res = 0;
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < n; ++i) {
            while (!stack.isEmpty() && heights[i] > heights[stack.peek()]) {
                int mid = stack.pop();
                if (stack.isEmpty()) { break; }
                int w = i - stack.peek() - 1;
                int h = Math.min(heights[i], heights[stack.peek()]) - heights[mid];
                res += h * w;
            }
            stack.push(i);
        }

        return res;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
