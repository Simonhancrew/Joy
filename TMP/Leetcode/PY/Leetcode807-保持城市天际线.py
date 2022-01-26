class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n,m = len(grid),len(grid[0])
        row,col = [0] * n,[0] * m
        for i in range(n):
            for j in range(m):
                row[i] = max(row[i],grid[i][j])
                col[j] = max(col[j],grid[i][j])
        res = 0
        for i in range(n):
            for j in range(m):
                res += min(col[j],row[i]) - grid[i][j]
        return res