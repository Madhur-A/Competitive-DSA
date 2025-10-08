



import java.util.*;

class Solution {
    public char lastChar(StringBuilder sb) { return sb.charAt(sb.length() - 1); }

    public String removeDuplicateLetters(String s) {
        int n = s.length();
        int[] lix = new int[26]; // last seen index

        for (int i = 0; i < n; ++i) {
            lix[s.charAt(i) - 'a'] = i;
        }

        StringBuilder res = new StringBuilder();
        boolean[]    seen = new boolean[26];

        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (!seen[c - 'a']) {
                while (!res.isEmpty() && c < lastChar(res) && i < lix[lastChar(res) - 'a']) {
                    seen[lastChar(res) - 'a'] = false;
                    res.deleteCharAt(res.length() - 1);
                }
                res.append(c);
                seen[c - 'a'] = true;
            }
        }

        return res.toString();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.removeDuplicateLetters("bcabc"));
        System.out.println(sol.removeDuplicateLetters("cbacdcbc"));
    }
}
