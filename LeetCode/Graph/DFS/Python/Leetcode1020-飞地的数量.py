class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        n, m, ans = len(grid), len(grid[0]), 0

        def dfs(x, y):
            nonlocal tag
            dx, dy = [0, -1, 0, 1], [-1, 0, 1, 0]
            ss = 1
            grid[x][y] = 0
            if not tag and (x == 0 or x == n - 1 or y == 0 or y == m - 1):
                tag = True
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
                if grid[nx][ny] == 0: continue
                ss += dfs(nx, ny)
            return ss

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    tag = False
                    ss = dfs(i, j)
                    if not tag: ans += ss
        return ans
