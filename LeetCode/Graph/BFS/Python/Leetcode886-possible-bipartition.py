class Solution:
    def possibleBipartition(self, n: int, dislikes) -> bool:
        g = [[] for _ in range(n + 1)]
        for d in dislikes:
            g[d[0]].append(d[1])
            g[d[1]].append(d[0])

        color = [0] * (n + 1)
        def dfs(u,c):
            color[u] = c
            for v in g[u]:
                if color[v] != 0:
                    if color[v] == color[u]:
                        return False
                elif not dfs(v, 3 - c):
                    return False
            return True 

        for i in range(1, n + 1):
            if color[i] == 0 and not dfs(i,1):
                return False
        return True