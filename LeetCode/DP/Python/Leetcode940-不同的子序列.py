class Solution:
    def distinctSubseqII(self, s: str) -> int:
        f,P = [0] * 26, int(1e9 + 7)
        f[ord(s[0]) - ord('a')] = 1
        for i in range(1, len(s)):
            rec = 0
            rec = (sum(f) + 1) % P
            f[ord(s[i]) - ord('a')] = rec
        return sum(f) % P