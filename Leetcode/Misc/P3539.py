



from typing import List
from itertools import permutations, combinations
from functools import lru_cache
from math import prod

class Solution:
    # let's make it as complicated as possible
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        n = len(nums)
        MOD = 1_000_000_007

        # factorials
        fact = [1] * (m + 1)
        for i in range(1, m + 1):
            fact[i] = fact[i - 1] * i % MOD
        inv_fact = [1] * (m + 1)
        inv_fact[m] = pow(fact[m], MOD - 2, MOD)
        for i in range(m, 0, -1):
            inv_fact[i - 1] = inv_fact[i] * i % MOD

        # precompute x^c / c!
        pow_num = []
        for x in nums:
            curr = [1] * (m + 1)
            for i in range(1, m + 1):
                curr[i] = curr[i - 1] * x % MOD
            for i in range(m + 1):
                curr[i] = curr[i] * inv_fact[i] % MOD
            pow_num.append(curr)

        get_dp = lambda : [[[0]*(m + 1) for _ in range(k + 1)] for __ in range(m + 1)]
        dp = get_dp()
        dp[0][0][0] = 1

        for i in range(n):
            new_dp = get_dp()
            pows = pow_num[i]

            for carry in range(m + 1):
                for ones in range(k + 1):
                    row = dp[carry][ones]
                    if not any(row):
                        continue

                    for c in range(m + 1):
                        factor = pows[c]
                        if factor == 0:
                            continue

                        total = carry + c
                        new_carry, bit = total >> 1, total & 1
                        new_ones = ones + bit

                        if new_ones > k or new_carry > m:
                            continue

                        for used in range(m - c + 1):
                            val = row[used]
                            if val:
                                new_dp[new_carry][new_ones][used + c] = (
                                    new_dp[new_carry][new_ones][used + c]
                                    + val * factor
                                ) % MOD

            dp = new_dp[:]
            new_dp.clear()

        # flush carry
        while True:
            changed = False
            new_dp = get_dp()
            for carry in range(1, m + 1):
                for ones in range(k + 1):
                    for used in range(m + 1):
                        val = dp[carry][ones][used]
                        if not val:
                            continue
                        changed = True
                        total = carry
                        new_carry, bit = total >> 1, total & 1
                        new_ones = ones + bit
                        if new_ones <= k:
                            new_dp[new_carry][new_ones][used] = (
                                new_dp[new_carry][new_ones][used] + val
                            ) % MOD

            # carry == 0
            for ones in range(k + 1):
                for used in range(m + 1):
                    new_dp[0][ones][used] = (
                        new_dp[0][ones][used] + dp[0][ones][used]
                    ) % MOD

            if not changed:
                break
            dp = new_dp[:]
            new_dp.clear()

        return dp[0][k][m] * fact[m] % MOD

    def magicalSumNaive(self, m: int, k: int, nums: List[int]) -> int:
        # mere depiction; as to what exactly is being computed (of course TLE)
        n = len(nums)
        res = 0
        indices = list(range(n))
        for c in combinations(indices, m):
            for each in permutations(c, k):
                res += prod([nums[i] for i in each])
                res %= 1_000_000_007
        return res

if __name__ == "__main__":
    sol = Solution()
    for m, k, nums in [(2, 2, [5,4,3,2,1])]:
        print("res: {}".format(sol.magicalSum(m, k, nums)))
    print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
