class Solution:
    def modifyString(self, s: str) -> str:
        rec,n = list(s),len(s)
        for i in range(n):
            if rec[i] == '?':
                for t in 'abc':
                    if (i > 0 and rec[i - 1] == t) or (i < n - 1 and rec[i + 1] == t): continue
                    rec[i] = t
                    break
        return ''.join(rec)