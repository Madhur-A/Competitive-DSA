



public class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        final int n = s.length();
        int[] prefixSum = new int[n + 1];
        for(int[] shift: shifts) {
            final int direction = (shift[2] == 0) ? -1 : 1;
            prefixSum[shift[0]]     += direction;
            prefixSum[shift[1] + 1] -= direction;
        }

        for(int i = 1; i < n + 1; ++i) {
            prefixSum[i] += prefixSum[i - 1];
        }

        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < n; ++i) {
            final int shift = (26 + (prefixSum[i] % 26)) % 26;
            final char newChar = (char) ('a' + (s.charAt(i) - 'a' + shift) % 26);
            ans.append(newChar);
        }

        return ans.toString();
    }
}
