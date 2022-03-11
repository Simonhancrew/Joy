class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        n,cnt,mx = len(parents),0,0
        sz,g = [0] * n,[[] for _ in range(n)]
        def dfs(u):
            sz[u] = 1
            tmp = 1
            nonlocal cnt,mx
            for s in g[u]:
                dfs(s)
                sz[u] += sz[s]
                tmp *= sz[s]
            if n - sz[u] > 0: tmp *= (n - sz[u])
            if tmp > mx:
                mx = tmp
                cnt = 1
            elif tmp == mx:
                cnt += 1
        
        for i in range(1,n):
            g[parents[i]].append(i)
        dfs(0)
        return cnt