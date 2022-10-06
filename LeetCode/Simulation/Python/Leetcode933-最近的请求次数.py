class RecentCounter:
    def __init__(self):
        self.q = deque()

    def ping(self, t: int) -> int:
        q = self.q
        q.append(t)
        while t - q[0] > 3000:
            q.popleft()
        return len(q)
