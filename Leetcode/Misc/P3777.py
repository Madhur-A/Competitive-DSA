



from typing import List
# from functools import lru_cache

# notice the mindlessness of this method; no fancy optimization,
# no thinking (except `merge`).
# the only significant benefit it has that it takes extremely short
# time to code; otherwise a lot more optimal methods exist.

class Solution:
    def minDeletions(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        t = [None for _ in range(4*n)]
        nums = list(s)

        def merge(L, R):
            if L is None: return R
            if R is None: return L
            sL, eL, cL = L
            sR, eR, cR = R
            return (sL, eR, cL + cR + (eL == sR))

        def build(node, start, end):
            if start == end:
                t[node] = (nums[start], nums[start], 0)
            else:
                mid = start + ((end - start) >> 1)
                build(2*node + 1, start, mid)
                build(2*node + 2, mid + 1, end)
                t[node] = merge(t[2*node + 1], t[2*node + 2])


        def update(node, start, end, index, value):
            if start == end:
                nums[index] = value
                t[node] = (value, value, 0)
            else:
                mid = start + ((end - start) >> 1)
                if index <= mid:
                    update(2*node + 1, start, mid, index, value)
                else:
                    update(2*node + 2, mid + 1, end, index, value)
                t[node] = merge(t[2*node + 1], t[2*node + 2])

        def dfs(node, start, end, left, right):
            if right < start or end < left: return None
            if left <= start and end <= right: return t[node]
            mid = start + ((end - start) >> 1)
            return merge(dfs(2*node + 1, start, mid, left, right), dfs(2*node + 2, mid + 1, end, left, right))

        def query(left, right):
            return dfs(0, 0, n - 1, left, right)

        # exec block
        build(0, 0, n - 1)
        res = []
        for q in queries:
            tp = q[0]
            if tp == 1:
                prev = nums[q[1]]
                val = 'A' if prev == 'B' else 'B'
                update(0, 0, n - 1, q[1], val)
            else:
                L, R = q[1], q[2]
                res.append(query(L, R)[2])
        return res

if __name__ == "__main__":
    sol = Solution()
    for s, queries in [("ABA", [[2,1,2],[1,1],[2,0,2]]), ("ABB", [[2,0,2],[1,2],[2,0,2]]), ("BABA", [[2,0,3],[1,1],[2,1,3]]), ("BABBB",[[1,1],[2,0,3],[2,3,3]])]:
        print("res: {}".format(sol.minDeletions(s, queries)));
    print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
