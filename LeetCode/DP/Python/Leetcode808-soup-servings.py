class Solution:
    def soupServings(self, n: int) -> float:
        n = (n + 24) // 25
        if n >= 200: return 1
        f = [[0] * (n + 1) for _ in range(n + 1)]
        def gen(x):
            return max(0, x)
        for i in range(n + 1):
            for j in range(n + 1):
                if i == j == 0: f[i][j] = 0.5
                elif i == 0 and j != 0: f[i][j] = 1
                elif i != 0 and j == 0: f[i][j] = 0
                else:
                    f[i][j] = (f[gen(i - 4)][j] + f[gen(i - 3)][gen(j - 1)] + f[gen(i - 2)][gen(j - 2)] + f[gen(i - 1)][gen(j - 3)]) / 4
        return f[n][n]