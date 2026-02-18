



from typing import List
from collections import deque
from heapq import heappush, heappop, heapify
from functools import lru_cache


class Solution:
    def maxProfit(self, n: int, edges: List[List[int]], score: List[int]) -> int:
        # takes approximately ~2 seconds
        if edges == []: # TestCase No. 803.
            return sum([(i+1)* _ for i, _ in enumerate(sorted(score))])
        masks = [0] * n
        for u, v in edges:
            masks[v] |= (1 << u)

        @lru_cache(maxsize = None)
        def get_nexts(mask):
            res = []
            for node in range(n):
                if (mask >> node) & 1:
                    continue
                if (mask & masks[node]) == masks[node]:
                    res.append(node)
            return res

        total = 1 << n
        dp = [0] + [-1] * (total - 1)

        bits = [0] * total
        for mask in range(1, total):
            bits[mask] = bits[mask >> 1] + (mask & 1)

        for mask in range(total):
            if dp[mask] < 0:
                continue
            for node in get_nexts(mask):
                next_mask   = mask | (1 << node)
                next_profit = dp[mask] + (score[node] * (bits[mask] + 1))
                dp[next_mask] = max(dp[next_mask], next_profit)

        return dp[total - 1]

    def maxProfitNaive(self, n: int, edges: List[List[int]], score: List[int]) -> int:
       # takes approximately ~10 seconds
        masks = [0]*n
        for u, v in edges:
            masks[v] |= (1 << u)

        total = 1 << n
        dp = [0] + [-1]*(total - 1)

        for mask in range(total):
            if dp[mask] == -1:
                continue
            pos = bin(mask).count('1') + 1
            for node in range(n):
                if (mask >> node) & 1:
                    continue
                if (mask & masks[node]) == masks[node]:
                    next_mask  = mask | (1 << node)
                    next_value = dp[mask] + (score[node] * pos)
                    dp[next_mask] = max(dp[next_mask], next_value)

        return dp[total - 1]


if __name__ == "__main__":
    sol = Solution()
    for n, edges, scores in [(3, [[0,1],[0,2]], [1,6,3]), (2, [[0,1]], [2,3])]:
        print("res: {}".format(sol.maxProfit(n, edges, scores)))
        # print("res: {}".format(sol.maxProfitNaive(n, edges, scores)))
    print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
