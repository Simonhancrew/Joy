class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n = len(words)
        bitmask = [0] * n
        for i in range(n):
            for ch in words[i]:
                t = ord(ch) - ord('a')
                bitmask[i] |= 1 << t
        res = 0
        for i in range(n):
            for j in range(i + 1,n):
                if bitmask[i] & bitmask[j] == 0:
                    res = max(res,len(words[i]) * len(words[j]))
        return res