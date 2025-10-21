



import java.util.*;

class Solution {
    public int[] maxValue(int[] nums) {
        int n = nums.length;
        int[] maxPrefix = new int[n], minSuffix = new int[n];
        maxPrefix[0] = nums[0];
        minSuffix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; ++i) { maxPrefix[i] = Math.max(maxPrefix[i - 1], nums[i]); }
        for (int i = n - 2; i > -1; --i) {
            minSuffix[i] = Math.min(minSuffix[i + 1], nums[i]);
           if (maxPrefix[i] > minSuffix[i + 1]) {
                maxPrefix[i] = maxPrefix[i + 1];
            }
        }

        return maxPrefix;
    }


    public static void main(String[] args) {
        System.out.println("------------------DONE------------------");
    }
}
