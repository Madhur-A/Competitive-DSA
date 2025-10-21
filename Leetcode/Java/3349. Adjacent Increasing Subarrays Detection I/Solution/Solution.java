



import java.util.*;

class Solution {
    public boolean isIncreasing(List<Integer> nums, int left, int right) {
        for (int i = left + 1; i < right; ++i) {
            if (nums.get(i - 1) >= nums.get(i)) {
                return false;
            }
        }
        return true;
    }

    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n + 1 - 2*k; ++i) {
            boolean first  = isIncreasing(nums, i, i + k);
            if (first && isIncreasing(nums, i + k, i + 2*k)) { return true; }
        }

        return false;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
