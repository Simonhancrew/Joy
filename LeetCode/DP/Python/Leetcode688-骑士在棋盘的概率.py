class Solution:
    def knightProbability(self, n: int, k: int, row: int,
                          column: int) -> float:
        dx, dy = [-2, -1, 1, 2, 2, 1, -1, -2], [1, 2, 2, 1, -1, -2, -2, -1]
        f = [[[0] * (k + 1) for _ in range(n)] for _ in range(n)]
        for st in range(k + 1):
            for i in range(n):
                for j in range(n):
                    if st == 0: f[i][j][st] = 1
                    else:
                        for d in range(8):
                            ni, nj = i + dx[d], j + dy[d]
                            if 0 <= ni < n and 0 <= nj < n:
                                f[i][j][st] += f[ni][nj][st - 1] / 8
        return f[row][column][k]
