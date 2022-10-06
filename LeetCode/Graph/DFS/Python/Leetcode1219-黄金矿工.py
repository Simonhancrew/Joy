class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        ans, n, m = 0, len(grid), len(grid[0])
        dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

        def dfs(x, y, beg):
            nonlocal ans
            beg += grid[x][y]
            ans, rec = max(ans, beg), grid[x][y]
            grid[x][y] = 0
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
                if grid[nx][ny] == 0: continue
                dfs(nx, ny, beg)
            grid[x][y] = rec

        for i in range(n):
            for j in range(m):
                if grid[i][j] != 0:
                    dfs(i, j, 0)
        return ans
