



import java.util.*;

class Solution {
    public int findLeft(int[] nums, int left, int target) {
        int right = nums.length - 1, mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == target) { return mid; }
            if (nums[mid] < target) {
                left  = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    public int lenLongestFibSubseq(int[] nums) {
        int n = nums.length, res = 0;
        // O(n^2 log n) logic; but avoids construction of 2D dp 
        // and other auxiliary structures such as HashMaps
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int found = findLeft(nums, j + 1, nums[i] + nums[j]), curr = 3;
                if (found != -1) {
                    int prev = nums[j], next = nums[j];
                    while (found != -1) {
                        prev = nums[found];
                        found = findLeft(nums, found + 1, next + nums[found]);
                        if (found != -1) { ++curr; next = prev; }
                    }
                    res = Math.max(res, curr);
                }
            }
        }
        return res;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
