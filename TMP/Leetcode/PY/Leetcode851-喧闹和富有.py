class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        ans = [-1] * n
        g = [[] for _ in range(n)]

        def dfs(u):
            if ans[u] != -1:return
            ans[u] = u
            for i in g[u]:
                dfs(i)
                if quiet[ans[i]] < quiet[ans[u]]:
                    ans[u] = ans[i]

        for rich in richer:
            a,b = rich[0],rich[1]
            g[b].append(a)
        for i in range(n):
            dfs(i)
        return ans