class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        n,m,ans = len(grid),len(grid[0]),[]
        for i in range(m):
            x,y,z = 0,i,0
            while x < n:
                if z == 0:
                    if grid[x][y] == 1:
                        if y + 1 >= m or grid[x][y + 1] == -1: y = -1
                        else: y,z = y + 1,1
                    else:
                        if y - 1 < 0 or grid[x][y - 1] == 1: y = -1
                        else: y,z = y - 1,1
                else:
                    x,z = x + 1,0
                if y == -1: break
            ans.append(y)
        return ans