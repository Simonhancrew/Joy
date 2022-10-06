class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        l, r, d, n = 0, 0, 0, len(grid)
        for i in range(n):
            tl, tr = 0, 0
            for j in range(n):
                if grid[i][j] != 0:
                    d += 1
                tl = max(tl, grid[i][j])
                tr = max(tr, grid[j][i])
            l += tl
            r += tr

        return l + r + d
