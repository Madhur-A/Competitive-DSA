



import java.util.*;

// another optimality problem
// categorized as dp.

class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        char[] sc = s.toCharArray();
        Deque<Integer> t = new ArrayDeque<>();
        t.add(0);

        int i = 0;
        while (!queue.isEmpty()) {
            if (t.peek() == n - 1) { return true; }
            int curr = t.poll();

            int left  = Math.max(current + minJump, i);
            int right = Math.min(current + maxJump, n - 1);

            for (int i = left; i < right + 1; i++) {
                if (sc[i] == '0') { t.add(i); }
            }

            i = i + 1;
        }

        return false;
    }

    public static void main(String[] args) {
        System.out.println("------------------DONE------------------");
    }
}
