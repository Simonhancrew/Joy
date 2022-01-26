from typing import List
from heapq import heappush,heappop
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        n,m = len(heightMap),len(heightMap[0])
        q = []
        st = [[False] * m for _ in range(n)]
        for i in range(0,m):
            heappush(q,(heightMap[0][i],0,i))
            heappush(q,(heightMap[n - 1][i],n - 1,i))
            st[0][i],st[n - 1][i] = True,True
        for i in range(1,n - 1):
            heappush(q,(heightMap[i][0],i,0))
            heappush(q,(heightMap[i][m - 1],i,m - 1))
            st[i][0],st[i][m - 1] = True,True
        res = 0
        dx,dy = [0,1,0,-1],[1,0,-1,0]
        while q:
            h,x,y = heappop(q)
            res += h - heightMap[x][y]
            for i in range(4):
                nx,ny = x + dx[i],y + dy[i]
                if 0 <= nx < n and 0 <= ny < m and not st[nx][ny]:
                    heappush(q,(max(heightMap[nx][ny],h),nx,ny))
                    st[nx][ny] = True
        return res