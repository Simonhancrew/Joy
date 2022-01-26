class Solution:
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:
        n,m = len(grid),len(grid[0])
        st = [[0] * m for _ in range(n)]
        dx,dy = [0,1,0,-1],[1,0,-1,0]
        def dfs(x,y):
            is_bd = False
            for i in range(4):
                a,b = dx[i] + x,dy[i] + y
                if 0 <= a < n and 0 <= b < m and grid[a][b] == grid[x][y]:
                    if st[a][b] == 0 :
                        st[a][b] = 1
                        dfs(a,b)
                else:
                    is_bd = True

            if is_bd: st[x][y] = 2
        st[row][col] = 1
        dfs(row,col)
        for i in range(n):
            for j in range(m):
                if st[i][j] == 2: grid[i][j] = color
        return grid
