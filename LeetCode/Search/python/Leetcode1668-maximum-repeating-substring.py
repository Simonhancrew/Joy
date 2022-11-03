class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        l, r = 0, len(sequence) // len(word)
        while l < r:
            mid = l + r + 1 >> 1
            s = word * mid
            if s in sequence: l = mid 
            else: r = mid - 1
        return l
