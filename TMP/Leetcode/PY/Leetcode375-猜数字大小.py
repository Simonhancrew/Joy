class Solution:
    def getMoneyAmount(self, n: int) -> int:
        f = [[0] * (n + 2) for _ in range(n+2)]
        for len in range(2,n + 1):
            l = 1
            while l + len - 1 <= n:
                r = l + len - 1
                f[l][r] = int(1e9)
                for k in range(l,r + 1):
                    f[l][r] = min(f[l][r],max(f[l][k - 1],f[k + 1][r]) + k)
                l += 1
        return f[1][n]
