# 模拟
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        res = ''
        for i in range(n):
            # 中心
            l,r = i - 1,i + 1
            while l >= 0 and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            if len(res) < r - l  - 1:
                res = s[l + 1:r]    
            # 无中心
            l,r = i,i + 1
            while l >= 0 and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            if len(res) < r - l - 1:
                res = s[l + 1:r]

        return res