



from typing import List
from collections import deque
from functools import lru_cache

class Solution:
    def concatenatedDivisibility(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        nums.sort()
        all_states = (1 << n)
        all_ones = all_states - 1 # 0b1111111111111111...
        powers = [pow(10, len(str(_)), k) for _ in nums]
        remainders = [_ % k for _ in nums]

        # using power-set config; wherein the lexically smallest property gets
        # held by `mask & (1 << i) == 0`. notice the complementary nature of this
        # variant, i.e., `mask & (1 << i) != 0` also generates subsets, but in
        # the reverse lexical order.

        @lru_cache(maxsize = None)
        def possible(mask, rem):
            if mask == all_ones: # exhausted all search space
                return rem == 0

            for i, num in enumerate(nums):
                if (mask & (1 << i)) == 0: # perhaps more readable than `(mask >> i) & 1`
                    next_mask = mask | (1 << i)
                    next_rem  = ((rem * powers[i]) + remainders[i]) % k
                    if possible(next_mask, next_rem):
                        return True
            return False

        if not possible(0, 0): return []
        res, mask, rem = [], 0, 0
        for _ in range(n):
            for i, num in enumerate(nums):
                if (mask & (1 << i)) == 0: # straight-up power-set config
                    next_mask = mask | (1 << i)
                    next_rem  = ((rem * powers[i]) + remainders[i]) % k
                    if possible(next_mask, next_rem):
                        res.append(num)
                        mask, rem = next_mask, next_rem
                        break
        return res



if __name__ == "__main__":
    sol = Solution()
    for nums, k in [([3,12,45], 5), ([10,5], 10), ([1,2,3], 5)]:
        print("res: {}".format(sol.concatenatedDivisibility(nums, k)))

    print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
