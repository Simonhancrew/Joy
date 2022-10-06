class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        n, m = len(matrix), len(matrix[0])
        r, c = [0] * n, [0] * m
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    r[i] = c[j] = 1
        for i in range(n):
            for j in range(m):
                if r[i] or c[j]:
                    matrix[i][j] = 0
