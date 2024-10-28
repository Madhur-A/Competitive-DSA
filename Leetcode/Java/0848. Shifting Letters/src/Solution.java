



public class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        final int n = s.length();
        long[] appliedShifts = new long[n];
        appliedShifts[n - 1] = shifts[n - 1];
        for(int i = n - 2; 0 <= i; --i) { appliedShifts[i] += shifts[i] + appliedShifts[i + 1]; }

        StringBuilder res = new StringBuilder();
        for(int i = 0; i < n; ++i) {
            final long totalShift = (s.charAt(i) - 'a' + appliedShifts[i]) % 26;
            final char newChar = (char) ('a' + totalShift);
            res.append(newChar);
        }
        return res.toString();
    }
}
