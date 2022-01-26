class Solution:

    def __init__(self, m: int, n: int):
        self._m = m
        self._n = n
        self.k = m * n
        self.mp = defaultdict(int)

    def flip(self) -> List[int]:
        idx = random.randint(0,self.k - 1)
        real = idx
        if idx in self.mp: real = self.mp[idx]
        if (self.k - 1) in self.mp:
            self.mp[idx] = self.mp[self.k - 1]
            del self.mp[self.k - 1]
        else:
            self.mp[idx] = self.k - 1
        self.k -= 1
        return [real // self._n,real % self._n]


    def reset(self) -> None:
        self.k = self._m * self._n
        self.mp = defaultdict()