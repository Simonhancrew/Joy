class Solution:
    def minJumps(self, arr: List[int]) -> int:
        mp,n = defaultdict(list),len(arr)
        for i,t in enumerate(arr):
            mp[t].append(i)
        q = deque([0])
        dist = [-1] * n
        dist[0] = 0
        while q:
            t = q.popleft()
            for ne in mp[arr[t]]:
                if dist[ne] == -1:
                    dist[ne] = dist[t] + 1
                    q.append(ne)
            mp.pop(arr[t])
            if t + 1 < n and dist[t + 1] == -1:
                dist[t + 1] = dist[t] + 1
                q.append(t + 1)
            if t - 1 >= 0 and dist[t - 1] == -1:
                dist[t - 1] = dist[t] + 1
                q.append(t - 1)
        return dist[-1]