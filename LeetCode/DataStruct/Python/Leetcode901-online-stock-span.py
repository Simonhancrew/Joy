class StockSpanner:

    def __init__(self):
        self.idx = 0
        self.stk = [[-1, int(1e6)]]

    def next(self, price: int) -> int:
        while price >= self.stk[-1][1]:
            self.stk.pop()
        res = self.idx - self.stk[-1][0]
        self.stk.append([self.idx, price])
        self.idx += 1
        return res
