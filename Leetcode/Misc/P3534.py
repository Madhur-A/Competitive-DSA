



from typing import List
from math import inf
from functools import lru_cache
from collections import deque

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        v_nums = [(num, i) for i, num in enumerate(nums)]
        v_nums.sort()
        n_nums = [num for (num, _) in v_nums]
        i_nums = {v_nums[i][1]: i for i in range(n)}

        rights = [0] * n
        right  = 0
        for left in range(n):
            while right < n and n_nums[right] - n_nums[left] <= maxDiff:
                right += 1
            rights[left] = right - 1

        splits, segs = 0, [0] * n
        for i in range(1, n):
            if n_nums[i] - n_nums[i - 1] > maxDiff:
                splits += 1
            segs[i] = splits

        res = [-1] * len(queries)
        for i, (u, v) in enumerate(queries):
            p, q = i_nums[u], i_nums[v]
            if p == q:
                res[i] = 0
            p, q = min(p, q), max(p, q)
            seen, t = [False]*n, deque([(p, 0)])
            seen[p] = True
            found  = -1
            while t:
                index, curr = t.popleft()
                if index >= q:
                    found = curr
                    break
                for nxxt in range(index + 1, right[index] + 1):
                    if not visited[nxxt]:
                        visited[nxxt] = True
                        t.append((nxxt, curr + 1))
            res[i] = found

        return res



if __name__ == "__main__":
    sol = Solution()
    for n, nums, maxDiff, queries in  [(5, [5,3,1,9,10], 2, [[0,1],[0,2],[2,3],[4,3]]), (5, [1,8,3,4,2], 3, [[0,3],[2,4]])]:
        print("res: {}".format(sol.pathExistenceQueries(n, nums, maxDiff, queries)))
    print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
