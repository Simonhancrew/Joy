class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        rec, ans = [-1] * 26, -1
        for i, c in enumerate(s):
            if rec[ord(c) - ord('a')] < 0:
                rec[ord(c) - ord('a')] = i
            else:
                ans = max(ans, i - rec[ord(c) - ord('a')] - 1)
        return ans
