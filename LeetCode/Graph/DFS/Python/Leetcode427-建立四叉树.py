class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        n = len(grid)
        rec = [[0] * (n + 1) for _ in range(n + 1)]
        def dfs(x1,y1,x2,y2):
            n = x2 - x1 + 1
            tot = rec[x2][y2] - rec[x2][y1 - 1] - rec[x1 - 1][y2] + rec[x1 - 1][y1 - 1]
            if tot == 0 or tot == n * n:
                return Node(0 if tot == 0 else 1,True)
            node = Node(0,False)
            m = n // 2
            node.topLeft = dfs(x1, y1, x1 + m - 1, y1 + m - 1)
            node.topRight = dfs(x1, y1 + m, x1 + m - 1, y2)
            node.bottomLeft = dfs(x1 + m, y1, x2, y1 + m - 1)
            node.bottomRight = dfs(x1 + m, y1 + m, x2, y2)
            return node
        for i in range(1,n + 1):
            for j in range(1,n + 1):
                rec[i][j] = rec[i - 1][j] + rec[i][j - 1] - rec[i - 1][j - 1] + grid[i - 1][j - 1]
        
        return dfs(1,1,n,n)