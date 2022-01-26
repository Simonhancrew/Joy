class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        f = [[0] *(k + 1) for _ in range(n + 1)]
        f[1][0] = 1
        mod = int(1e9 + 7)
        for i in range(2,n + 1):
            s = 0
            for j in range(0,k + 1):
                s += f[i - 1][j]
                if j - i >= 0:
                    s -= f[i - 1][j - i]
                f[i][j] = s % mod
        return f[n][k]