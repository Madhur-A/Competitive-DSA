



import java.util.*;

class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] windowSums = new int[n - k + 1];
        int[] leftIdx = new int[n - k + 1], rightIdx = new int[n - k + 1];

        for (int i = 0, total = 0; i < n; ++i) {
            total += nums[i];
            if (i > k - 1) { total -= nums[i - k]; }
            if (i > k - 2) { windowSums[i - k + 1] = total; }
        }

        for (int j = 0, idx = 0; j < n - k + 1; ++j) {
            if (windowSums[j] > windowSums[idx]) {
                idx = j;
            }
            leftIdx[j] = idx;
        }

        for (int j = n - k, idx = n - k; j > -1; --j) {
            if (windowSums[j] >= windowSums[idx]) {
                idx = j;
            }
            rightIdx[j] = idx;
        }

        int currTotal = 0, maxSoFar = 0;
        int[] ans = new int[3];

        // this is the supposed DP part of this otherwise
        // pure SW problem

        for (int mid = k; mid < n - 2*k + 1; ++mid) {
            currTotal = windowSums[leftIdx[mid - k]] + windowSums[mid] + windowSums[rightIdx[mid + k]];
            if (currTotal > maxSoFar) {
                maxSoFar = currTotal;
                ans[0] = leftIdx[mid - k]; ans[1] = mid; ans[2] = rightIdx[mid + k];
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(Arrays.toString(sol.maxSumOfThreeSubarrays(new int[]{1,2,1,2,6,7,5,1}, 2)));
        System.out.println("------------------DONE------------------");
    }
}
