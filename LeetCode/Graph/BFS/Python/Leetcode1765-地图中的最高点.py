class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        n,m = len(isWater),len(isWater[0])
        ans = [[0] * m for _ in range(n)]
        st = [[False] * m for _ in range(n)]
        q = deque()
        for i in range(n):
            for j in range(m):
                if isWater[i][j] == 1: 
                    q.append([[i,j],0])
        dx,dy = [0,-1,0,1],[-1,0,1,0]
        while q:
            t = q.popleft()
            x,y,hi = t[0][0],t[0][1],t[1]
            for i in range(4):
                nx,ny = x + dx[i],y + dy[i]
                if nx < 0 or nx >= n or ny  < 0 or ny >= m: continue
                if st[nx][ny] or isWater[nx][ny] == 1: continue
                st[nx][ny] = True
                ans[nx][ny] = hi + 1
                q.append([[nx,ny],hi + 1])
        return ans