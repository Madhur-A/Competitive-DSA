




from typing import List
from functools import lru_cache
from math import inf

# basically another one of optimization problem; see 3287 for
# a similar problem; it's naive solution is:

# Signature: f(nums)
# Docstring: 2035
# Source:
# def f(nums):
#     n = len(nums)
#     m = 1 << n
#     t = sum(nums)

#     res = inf
#     for i in range(m):
#         curr, lst = 0, 0
#         for j in range(n):
#             if i & (1 << j):
#                 curr += nums[j]
#                 lst  += 1
#         rst = t - curr
#         if lst != (n >> 1): continue
#         res = min(res, abs(rst - curr))

#     return res
# File:      ~/anaconda3/<ipython-input-89-cea86896204d>
# Type:      function

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        # one of the fundamental trick is to partition it in two halves
        n = len(nums)
        h = n >> 1 # the so-called pivot

        full, half = sum(nums), sum(nums) >> 1

        # arranging the subsets sums according to their lengths
        left, right = [[] for _ in range(h + 1)], [[] for _ in range(h + 1)]
        left[0].append(0)
        right[0].append(0)

        for i in range(h):
            num = nums[i]
            for length in range(i, -1, -1): # this is imperative; as to not clash the frequency
                for prev in left[length]:
                    left[length + 1].append(prev + num)

        for i in range(h, n):
            num = nums[i]
            for length in range(i - h, -1, -1):
                for prev in right[length]:
                    right[length + 1].append(prev + num)

        res, candidate = inf, -inf
        for length in range(h + 1): # faster than binary serach in practice
            rest = h - length
            L, R = sorted(left[length]), sorted(right[rest], reverse = True)
            i, j = 0, 0
            while i < len(L) and j < len(R):
                curr = L[i] + R[j]
                if curr == half:
                    return full - 2*half # micro but essential optimization
                if curr > half:
                    j += 1
                else:
                    i += 1
                    candidate = max(candidate, curr)
            res = min(res, full - 2*candidate)

        return res


if __name__ == "__main__":
    sol = Solution()
    for t in ([3,9,7,3], [-36,36], [2,-1,0,4,-2,-9]):
        print("res: {}".format(sol.minimumDifference(t)))
    print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
