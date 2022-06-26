class Solution:

    def __init__(self, n: int, blacklist: List[int]):
        self.n = n
        self.m = len(blacklist)
        self.mp = defaultdict(int)
        m,st = self.m,set()
        for i in range(n - m,n): st.add(i)
        for i in blacklist: st.discard(i)
        it = iter(st)
        for i in blacklist:
            if i < n - m: self.mp[i] = next(it)

    def pick(self) -> int:
        k = random.randrange(self.n - self.m)
        if k in self.mp: return self.mp[k]
        return k