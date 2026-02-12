



from typing import List

class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)

        parity = lambda num: 1 if num & 1 else -1

        # preprocess `nums`
        nexts, lasts = [n]*(n), [n]*(100_001)
        odds, even = 0, 0

        # [!]
        for i in range(n-1, -1, -1):
            p = parity(nums[i])
            if p == 1:
                odds += 1
            else:
                even += 1
            nexts[i] = lasts[nums[i]]
            lasts[nums[i]] = i

        if odds == 0 or even == 0:
            return 0 # pointless to proceed further

        prefix = [0]*(n)
        seen   = [False]*(100_001)
        for i, num in enumerate(nums):
            prev = 0 if i == 0 else prefix[i - 1]
            prefix[i] = prev
            if not seen[num]:
                seen[num] = True
                prefix[i] += parity(num)

        if prefix[-1] == n:
            return n # another short-circuit

        maxs, mins, lazy = [0]*(4*n), [0]*(4*n), [0]*(4*n)
        # `lazy` is more of an triggering array rather than the cumulative one

        def build(node, start, end):
            if start == end:
                # notice the absence of `lazy`
                maxs[node], mins[node] = prefix[start], prefix[start]
            else:
                mid = start + ((end - start) >> 1)
                build(2*node + 1, start, mid)
                build(2*node + 2, mid + 1, end)
                maxs[node] = max(maxs[2*node + 1], maxs[2*node + 2])
                mins[node] = min(mins[2*node + 1], mins[2*node + 2])

        build(0, 0, n - 1)

        def invoke(node, delta):
            mins[node] += delta
            maxs[node] += delta
            lazy[node] += delta

        def find_from_last(node, start, end, left, target):
            if end < left or maxs[node] < target or mins[node] > target: return None
            if start == end: return start
            if lazy[node] != 0:
                invoke(2*node + 1, lazy[node])
                invoke(2*node + 2, lazy[node])
                lazy[node] = 0
            mid = start + ((end - start) >> 1)
            found = find_from_last(2*node + 2, mid + 1, end, left, target)
            if found is not None:
                return found
            return find_from_last(2*node + 1, start, mid, left, target)

        def ranged_add(node, start, end, left, right, delta):
            if left <= start and end <= right:
                mins[node] += delta
                maxs[node] += delta
                lazy[node] += delta
            else:
                if lazy[node] != 0:
                    invoke(2*node + 1, lazy[node])
                    invoke(2*node + 2, lazy[node])
                    lazy[node] = 0
                mid = start + ((end - start) >> 1)
                if left <= mid:
                    ranged_add(2*node + 1, start, mid, left, right, delta)
                if right > mid:
                    ranged_add(2*node + 2, mid + 1, end, left, right, delta)
                maxs[node] = max(maxs[2*node + 1], maxs[2*node + 2])
                mins[node] = min(mins[2*node + 1], mins[2*node + 2])

        # driving-content
        res = 0

        for left, num in enumerate(nums):
            if left + res >= n: break # futile to proceed
            right = find_from_last(0, 0, n - 1, left, 0) # looking for 0 from the last
            if right is not None: # if found
                res = max(res, right - left + 1) # update `res`
            nxt = nexts[left] # in any case,
            if nxt > left + 1:
                # removing this specific num's contribution from its
                # range
                ranged_add(0, 0, n - 1, left + 1, nxt - 1, -parity(num))

        return res


if __name__ == "__main__":
    tests = [[9,20,5,11,20,20],[2,5,4,3],[3,2,2,5,4]]
    sol = Solution()
    for test, ans in zip(tests, [3,4,5]):
        res = sol.longestBalanced(test)
        assert(res == ans)
        print(test, res)
    print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
