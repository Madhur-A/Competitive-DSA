



import java.util.*;
import java.util.stream.*;

class Solution {
    public long gcd(long a, long b) { return a == 0 ? b : gcd(b % a, a); }

    public long lcm(long a, long b) { return (a * b) / gcd(a, b); }

    public List<Integer> replaceNonCoprimes(int[] nums) {
        int n = nums.length;
        Deque<Long> stack = new ArrayDeque<>();
        stack.push((long)nums[0]);

        for (int i = 1; i < n; ++i) {
            long last = (long)nums[i];
            while (!stack.isEmpty() && gcd(stack.peekLast(), last) > 1) {
                last = lcm(stack.pollLast(), last);
            }
            stack.addLast(last);
        }


        return stack.stream().map(Math::toIntExact).collect(Collectors.toList());
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
