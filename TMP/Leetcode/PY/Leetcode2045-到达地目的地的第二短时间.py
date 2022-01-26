class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        graph = [[] for _ in range(n + 1)]
        for u,v in edges:
            graph[u].append(v)
            graph[v].append(u)
        d1,d2 = [int(1e10)] * (n + 1),[int(1e10)] * (n + 1)
        q = deque()
        q.append([0,1])
        while q:
            t = q.popleft()
            d,node = t
            for ne in graph[node]:
                if d1[ne] > d + 1:
                    d2[ne] = d1[ne]
                    d1[ne] = d + 1
                    q.append([d + 1,ne])
                elif d1[ne] < d + 1 and d2[ne] > d + 1:
                    d2[ne] = d + 1
                    q.append([d + 1,ne])
        ans = 0
        for i in range(d2[n]):
            a,b = ans // change,ans % change
            wait = 0 if a % 2 == 0 else change - b
            ans += wait + time
        return ans
