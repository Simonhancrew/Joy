class Solution:
    def maxScore(self, s: str) -> int:
        cnt, n = 0, len(s)
        for ch in s:
            if ch == '1': cnt += 1
        lhs, rhs, res = 0, cnt, 0
        for i in range(n - 1):
            if s[i] == '0': lhs += 1
            else: rhs -= 1
            res = max(res, lhs + rhs)
        return res
