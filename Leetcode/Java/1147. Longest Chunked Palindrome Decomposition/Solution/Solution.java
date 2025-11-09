



import java.util.*;

class Solution {
    // an inherent greedy problem
    public int rx(String s, int left, int right, int len) {
        if (left       >=      right) { return 0; }
        if (left + len > right - len) { return 1; }

        String leftString  = s.substring(left, left + len);
        String rightString = s.substring(right - len, right);

        return (leftString.equals(rightString)) ? 2 + rx(s, left + len, right - len, 1) : rx(s, left, right, len + 1);
    }

    public int longestDecomposition(String s) {
        int n = s.length();
        return rx(s, 0, n, 1);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.printf("res = %d\n", sol.longestDecomposition("ghiabcdefhelloadamhelloabcdefghi"));
        System.out.println("------------------DONE------------------");
    }
}
