class OrderedStream:

    def __init__(self, n: int):
        self.mp = defaultdict(str)
        self.ptr = 1


    def insert(self, idKey: int, value: str) -> List[str]:
        self.mp[idKey] = value
        ans = []
        if self.ptr not in self.mp: return ans
        while self.ptr in self.mp:
            ans.append(self.mp[self.ptr])
            self.ptr += 1
        return ans
