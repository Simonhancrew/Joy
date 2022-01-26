class Solution:
    def balancedStringSplit(self, s: str) -> int:
        res = cnt = 0
        for i in range(len(s)):
            if s[i] == 'R':
                cnt += 1
            else:
                cnt -= 1
            if cnt == 0:
                res += 1
        return res