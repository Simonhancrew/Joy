class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        n = len(s)
        start, length = 0, 0
        for l in range(0, n):
            a, b = 0, 0
            for r in range(l, n):
                if s[r].islower():
                    a |= 1 << (ord(s[r]) - ord('a'))
                else:
                    b |= 1 << (ord(s[r]) - ord('A'))
                if a == b and r - l + 1 > length:
                    start, length = l, r - l + 1
        return s[start:start + length]
