



from typing import List

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        # straight-up union find
        roots = list(range(n + 1))
        ranks = [0] * (n + 1)
        def find(node):
            if roots[node] == node:
                return node
            roots[node] = find(roots[node])
            return roots[node]

        def union(u, v):
            p, q = find(u), find(v)
            if p != q and abs(nums[u] - nums[v]) <= maxDiff:
                if ranks[p] <= ranks[q]:
                    roots[q] = roots[p]
                    ranks[p] = ranks[p] + (1 if ranks[p] == ranks[q] else 0)
                else:
                    roots[p] = roots[q]

        for i in range(1, n):
            union(i, i - 1)

        return [find(u) == find(v) for u, v in queries]

    def pathExistenceQueriesOpt(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        # better still; using only split-depths
        splits, segments = 0, [0] * (n + 1)
        for i in range(1, n):
            if nums[i] - nums[i - 1] > maxDiff: # graph becomes disjoint here
                splits += 1
            segments[i] = splits # hence higher depth (what an oxymoron, lol)

        return [segments[u] == segments[v] for u, v in queries] # i.e. if same depth


if __name__ == "__main__":
    sol = Solution()
    for n, nums, maxDiff, queries in  [(2, [1,3], 1, [[0,0],[0,1]]), (4, [2,5,6,8], 2, [[0,1],[0,2],[1,3],[2,3]])]:
        # print("res: {}".format(sol.pathExistenceQueries(n, nums, maxDiff, queries)))
        print("res: {}".format(sol.pathExistenceQueriesOpt(n, nums, maxDiff, queries)))
    print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
