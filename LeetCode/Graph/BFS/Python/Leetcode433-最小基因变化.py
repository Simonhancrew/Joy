class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        id = ['A','C','G','T']
        st,q,dist = set(bank),deque(),defaultdict(int)
        dist[start] = 0
        q.append(start)
        while q:
            t = q.popleft()
            for i in range(8):
                s = list(t)
                for ch in id:
                    s[i] = ch
                    ss = ''.join(s)
                    if ss in st and ss not in dist:
                        dist[ss] = dist[t] + 1
                        if ss == end: return dist[ss]
                        q.append(ss)
        return -1