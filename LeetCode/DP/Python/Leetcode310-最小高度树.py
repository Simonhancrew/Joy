class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        g, d1, d2, up, p1 = [[] for _ in range(n)
                             ], [0] * n, [0] * n, [0] * n, [0] * n
        for ed in edges:
            a, b = ed[0], ed[1]
            g[a].append(b)
            g[b].append(a)

        def dfs1(u, fa):
            for x in g[u]:
                if x == fa: continue
                dfs1(x, u)
                d = d1[x] + 1
                if d >= d1[u]:
                    d2[u], d1[u] = d1[u], d
                    p1[u] = x
                elif d > d2[u]:
                    d2[u] = d

        def dfs2(u, fa):
            for x in g[u]:
                if x == fa: continue
                if p1[u] == x: up[x] = max(up[u], d2[u]) + 1
                else: up[x] = max(up[u], d1[u]) + 1
                dfs2(x, u)

        dfs1(0, -1)
        dfs2(0, -1)

        mind, res = n + 1, []
        for i in range(n):
            mind = min(mind, max(d1[i], up[i]))
        for i in range(n):
            if max(up[i], d1[i]) == mind:
                res.append(i)
        return res
