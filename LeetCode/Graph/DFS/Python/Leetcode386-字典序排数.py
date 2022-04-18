class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        res = []
        def dfs(cur,n):
            if cur <= n:
                res.append(cur)
            else:
                return
            for i in range(0,10):
                dfs(cur * 10 + i,n)
        for i in range(1,10): dfs(i,n)
        return res