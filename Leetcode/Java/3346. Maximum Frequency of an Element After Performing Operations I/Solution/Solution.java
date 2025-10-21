



import java.util.*;

class Solution {
    public int findLeft(int[] nums, int target) {
        int left = 0, right = nums.length, mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    public int maxFrequency(int[] nums, int k, int ops) {
        int n = nums.length;
        Arrays.sort(nums);
        int[] freq = new int[100001];

        int min = 1 << 30, max = 0, res = 0;

        for (int i = 0; i < n; ++i) {
            min = Math.min(min, nums[i]);
            max = Math.max(max, nums[i]);
            freq[nums[i]] += 1;
        }

        for (int num = min; num < max + 1; ++num) {
            int left = findLeft(nums, num - k), right = findLeft(nums, num + k + 1);
            int found = right - left - freq[num];
            res = Math.max(res, freq[num] + Math.min(found, ops));
        }

        return res;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
