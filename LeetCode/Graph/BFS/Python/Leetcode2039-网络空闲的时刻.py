class Solution:
    def networkBecomesIdle(self, edges: List[List[int]],
                           patience: List[int]) -> int:
        n = len(patience)
        g = [[] for _ in range(n)]
        for edge in edges:
            g[edge[0]].append(edge[1])
            g[edge[1]].append(edge[0])

        q, d = deque([0]), [n] * n
        d[0] = 0
        while q:
            t = q.popleft()
            for v in g[t]:
                if d[v] > d[t] + 1:
                    d[v] = d[t] + 1
                    q.append(v)

        ans = 0
        for i in range(1, n):
            di, t = 2 * d[i], patience[i]
            cur = di if di <= patience[i] else (di - 1) // t * t + di
            ans = max(cur, ans)
        return ans + 1
