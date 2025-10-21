



import java.util.*;

class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int n = nums.size(), res = 1;
        int[] maxLens = new int[n];
        maxLens[0] = 1;

        for (int i = 1; i < n; ++i) {
            maxLens[i] = nums.get(i - 1) < nums.get(i) ? maxLens[i - 1] + 1 : 1;
        }

        for (int i = 0; i < n; ++i) {
            int len = maxLens[i];
            if (len % 2 == 0) { res = Math.max(res, len >> 1); }
            if (i + len < n) {
                if (maxLens[i] == maxLens[i + len]) {
                    res = Math.max(res, len);
                    continue;
                }
            }
            int left = 0, right = len, mid = 0;
            while (len > res && left < right) {
                mid = (left + right) >> 1;
                if (i + mid < n && maxLens[i + mid] == mid) {
                    res   = Math.max(res, mid);
                    left  = mid + 1;
                } else {
                    right = mid;
                }
            }

        }


        return res;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
