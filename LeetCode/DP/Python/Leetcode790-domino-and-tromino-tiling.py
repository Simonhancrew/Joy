class Solution:
    def numTilings(self, n: int) -> int:
        p = int(1e9) + 7
        w = [[1, 1, 1, 1], [0, 0, 1, 1], [0, 1, 0, 1], [1, 0, 0, 0]]
        f = [[0] * 4 for _ in range(n + 1)]
        f[0][0] = 1
        for i in range(n):
            for j in range(4):
                for k in range(4):
                    f[i + 1][k] = (f[i + 1][k] + f[i][j] * w[j][k]) % p
        return f[n][0]