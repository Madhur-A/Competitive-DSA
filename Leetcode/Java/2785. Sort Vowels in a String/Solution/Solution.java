



import java.util.*;

class Solution {
    public boolean isVowel(char c) { return "aeiouAEIOU".indexOf(c) != -1; }

    public String sortVowels(String s) {
        int n = s.length();
        char[] sc = s.toCharArray(), have = new char[n + 1];
        Arrays.fill(have, (char)255);

        for (int i = 0, j = 0; i < n; ++i) {
            if (isVowel(sc[i])) {
                have[j++] = sc[i];
            }
        }

        Arrays.sort(have);
        StringBuilder res = new StringBuilder();

        for (int i = 0, j = 0; i < n; ++i) {
            if (isVowel(sc[i])) {
                res.append(have[j++]);
            } else {
                res.append(sc[i]);
            }
        }

        return res.toString();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.sortVowels("alkdflkasjekwiueoiwad"));
    }
}
