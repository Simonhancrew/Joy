class Solution:
    def alternateDigitSum(self, n: int) -> int:
        s = str(n)
        ans, pos = 0, 1
        for i in range(len(s)):
            ans += (ord(s[i]) - ord('0')) * pos
            pos *= -1
        return ans