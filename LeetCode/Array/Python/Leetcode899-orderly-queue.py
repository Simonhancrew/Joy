class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        if k == 1:
            res = s
            for i in range(len(s)):
                s = s[1:] + s[0]
                res = min(res,s)
            return res
        s = list(s)
        s.sort()
        return ''.join(s)