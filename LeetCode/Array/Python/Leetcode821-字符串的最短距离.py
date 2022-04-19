class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        res = [100000] * n
        idx = -1
        for i in range(n):
            if s[i] == c: idx = i
            if idx != -1: res[i] = i - idx
        idx = -1
        for i in range(n - 1,-1,-1):
            if s[i] == c: idx = i
            if idx != -1: res[i] = min(res[i],idx - i)

        return res