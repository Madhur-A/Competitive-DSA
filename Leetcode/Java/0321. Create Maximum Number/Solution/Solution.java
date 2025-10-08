



import java.util.*;

class Solution {
    // typical `merge-sort` based
    public int[] getMax(int[] nums, int k) {
        int n = nums.length;
        Deque<Integer> stack = new ArrayDeque<>();
        int count = n - k;
        for (int i = 0; i < n; ++i) {
            while (!stack.isEmpty() && count > 0 && nums[i] > nums[stack.peekLast()]) {
                stack.pollLast();
                count -= 1;
            }
            stack.addLast(i);
        }

        return stack.stream().limit(k).mapToInt(i -> nums[i]).toArray();
    }

    public int compare(int[] a, int i, int[] b, int j) {
        while (i < a.length && j < b.length) {
            if (a[i] != b[j]) { return a[i] - b[j]; }
            i += 1;
            j += 1;
        }
        return (a.length - i) - (b.length - j);
    }

    public int[] merge(int[] a, int[] b) {
        int[] res = new int[a.length + b.length];
        int i = 0, j = 0, r = 0;
        while (i < a.length || j < b.length) {
            if (compare(a, i, b, j) > 0) {
                res[r++] = a[i++];
            } else {
                res[r++] = b[j++];
            }
        }

        return res;
    }

    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int n = nums1.length, m = nums2.length;
        int[] maxRes = new int[k];
        for (int i = Math.max(0, k - m); i < Math.min(k, n) + 1; ++i) {
            int[] localRes = merge(getMax(nums1, i), getMax(nums2, k - i));
            if (compare(localRes, 0, maxRes, 0) > 0) {
                maxRes = localRes;
            }
        }

        return maxRes;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums1 = new int[]{6,7}; //{3,4,6,5};
        int[] nums2 = new int[]{6,0,4}; //{9,1,2,5,8,3};
        int k = 5;
        System.out.println(Arrays.toString(sol.maxNumber(nums1, nums2, k)));
    }
}
