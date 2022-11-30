class FreqStack:

    def __init__(self):
        self.rec = defaultdict(list)
        self.freq = defaultdict(int)
        self.mx = 0

    def push(self, val: int) -> None:
        self.freq[val] += 1
        self.mx = max(self.mx, self.freq[val])
        self.rec[self.freq[val]].append(val)

    def pop(self) -> int:
        res = self.rec[self.mx].pop()
        self.freq[res] -= 1
        if not self.rec[self.mx]: 
            self.mx -= 1
        return res


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()