class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        f = [[[-100000] * (2 * n + 1) for _ in range(n + 1)]
             for _ in range(n + 1)]
        f[1][1][2] = grid[0][0]
        for k in range(3, 2 * n + 1):
            for i in range(max(1, k - n), min(n + 1, k)):
                for j in range(max(1, k - n), min(n + 1, k)):
                    if grid[i - 1][k - i - 1] == -1 or grid[j - 1][k - j -
                                                                   1] == -1:
                        continue
                    t = grid[i - 1][k - i - 1]
                    if i != j: t += grid[j - 1][k - j - 1]
                    for a in range(i - 1, i + 1):
                        for b in range(j - 1, j + 1):
                            f[i][j][k] = max(f[i][j][k], f[a][b][k - 1] + t)
        return max(0, f[n][n][2 * n])
