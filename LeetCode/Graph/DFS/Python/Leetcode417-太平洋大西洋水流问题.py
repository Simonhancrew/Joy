class Solution:
    def pacificAtlantic(self, g: List[List[int]]) -> List[List[int]]:
        dx,dy = [0,1,0,-1],[1,0,-1,0]
        n,m = len(g),len(g[0])
        st = [[0] * m for _ in range(n)]
        def dfs(x,y,t):
            if (st[x][y] & t != 0): return
            st[x][y] |= t
            for i in range(4):
                nx,ny = x + dx[i],y + dy[i]
                if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
                if g[nx][ny] < g[x][y]: continue
                dfs(nx,ny,t)
        res = []
        for i in range(n): 
            dfs(i,0,1)
            dfs(i,m - 1,2)
        for i in range(m):
            dfs(0,i,1)
            dfs(n - 1,i,2)
        for i in range(n):
            for j in range(m):
                if st[i][j] == 3:
                    res.append([i,j])
        return res
