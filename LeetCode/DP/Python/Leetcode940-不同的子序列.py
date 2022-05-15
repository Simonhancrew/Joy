class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD,n = int(1e9) + 7,len(s)
        f = [[0] * 26 for _ in range(n + 1)]
        for i in range(n):
            t = ord(s[i]) - ord('a')
            f[i + 1][t] = 1
            for j in range(26):
                f[i + 1][t] = (f[i + 1][t] + f[i][j]) % MOD
                if t != j:
                    f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD
        res = 0
        for x in f[n]:
            res = (res + x) % MOD
        return res