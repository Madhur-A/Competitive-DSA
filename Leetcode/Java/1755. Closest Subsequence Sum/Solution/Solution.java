



import java.util.*;

class Solution {
    public int findLeft(List<Long> nums, long target) {
        int left = 0, right = nums.size(), mid = 0;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (nums.get(mid) < target) {
                left  = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    public List<Long> generateSubsetSums(int[] nums) {
        int n = nums.length, maxLen = 1 << n;
        List<Long> subSum = new ArrayList<>();
        for (int i = 0; i < maxLen; ++i) {
            long total = 0L;
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    total += nums[j];
                }
            }
            subSum.add(total);
        }

        return subSum;
    }

    public int minAbsDifference(int[] nums, int goal) {
        // notice `(2^{n + 1}) < (2^{2n})` or `2097152 < 1099511627776`.
        // this makes it more or less a constructive type rather than
        // a DP type. the rest is simply binary search over subset sums
        // of one half while iterating over the other.

        int n = nums.length, h = n >> 1;
        int[] firstHalf = new int[h], secondHalf = new int[n - h];
        for (int i = 0, j = 0; i < n; ++i) {
            if (i < h) {
                firstHalf[i] = nums[i];
            } else {
                secondHalf[j++] = nums[i];
            }
        }

        List<Long> firstSub = generateSubsetSums(firstHalf), secondSub = generateSubsetSums(secondHalf);
        secondSub.sort(null);

        long res = Integer.MAX_VALUE;
        int len = secondSub.size();

        for (long sum: firstSub) {
            int curr = Math.min(len - 1, findLeft(secondSub, goal - sum)), prev = Math.max(0, curr - 1);
            res = Math.min(res, Math.abs(secondSub.get(curr) + sum - goal));
            res = Math.min(res, Math.abs(secondSub.get(prev) + sum - goal));
            if (res == 0) { return 0; }
        }

        return (int)res;
    }

    public static void main(String[] args) {
        System.out.println("------------------DONE------------------");
    }
}
