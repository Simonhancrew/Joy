class Solution:
    def maxPower(self, s: str) -> int:
        i,j,res = 0,0,0
        while i < len(s):
            while j < len(s) and s[i] == s[j]: j += 1
            res = max(res,j - i)
            i = j
        return res