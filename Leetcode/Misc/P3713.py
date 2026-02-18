



class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        res = 0
        for left in range(n):
            freq, maxf, dist = [0]*26, 0, 0
            for right in range(left, n):
                c = ord(s[right]) - ord('a')
                if freq[c] == 0:
                    dist += 1
                freq[c] += 1
                maxf = max(maxf, freq[c])
                ln = right - left + 1
                if maxf * dist == ln: #[!]
                    res = max(res, ln)
        return res

if __name__ == "__main__":
    sol = Solution()
    tests = ["abbac", "zzabccy", "aba"]
    for test, ans in zip(tests, [4,4,2]):
        res = sol.longestBalanced(test)
        assert(res == ans)
    print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
