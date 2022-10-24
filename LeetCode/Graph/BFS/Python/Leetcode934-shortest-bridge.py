class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dis = [[int(1e6)] * m for _ in range(n)]
        q = deque()
        dx,dy = [0, -1, 0, 1], [-1, 0, 1, 0]
        
        def dfs(x,y):
            q.append([x, y])
            dis[x][y] = 0
            grid[x][y] = 0
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if nx >= 0 and ny >= 0 and nx < n and ny < m and grid[nx][ny]:
                    dfs(nx, ny)
        
        def bfs():
            while q:
                t = q.popleft()
                for i in range(4):
                    nx, ny = t[0] + dx[i], t[1] + dy[i]
                    if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
                    if grid[nx][ny] == 1: return dis[t[0]][t[1]] 
                    if dis[nx][ny] > dis[t[0]][t[1]] + 1:
                        dis[nx][ny] = dis[t[0]][t[1]] + 1
                        q.append([nx, ny])
            return -1                

        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    dfs(i,j)
                    return bfs()
        return -1