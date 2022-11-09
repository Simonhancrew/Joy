class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        g, f = [[1] * n for _ in range(n)], [[0] * n for _ in range(n)]
        for x in mines: g[x[0]][x[1]] = 0
        for i in range(n):
            s = 0
            for j in range(n):
                if g[i][j]: s += 1
                else: s = 0
                f[i][j] = s

        for i in range(n):
            s = 0
            for j in range(n - 1, -1, -1):
                if g[i][j]: s += 1
                else: s = 0
                f[i][j] = min(f[i][j], s)

        for j in range(n):
            s = 0
            for i in range(n):
                if g[i][j]: s += 1
                else: s = 0
                f[i][j] = min(f[i][j], s)

        for j in range(n):
            s = 0
            for i in range(n - 1, -1, -1):
                if g[i][j]: s += 1
                else: s = 0
                f[i][j] = min(f[i][j], s)
        res = 0
        for i in range(n):
            for j in range(n):
                res = max(f[i][j], res)

        return res

