



import java.util.*;

class Solution {
    public int findLeft(int[] nums, int spell, long target) {
        int left = 0, right = nums.length, mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] * (long)spell < target) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums.length - left;
    }

    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = potions.length;
        Arrays.sort(potions);

        int[] ans = new int[spells.length];

        for (int i = 0; i < spells.length; ++i) {
            ans[i] = findLeft(potions, spells[i], success);
        }

        return ans;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
