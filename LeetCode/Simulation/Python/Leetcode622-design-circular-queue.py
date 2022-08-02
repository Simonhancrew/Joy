class MyCircularQueue:

    def __init__(self, k: int):
        self.q = [0] * (k + 1)
        self.hh = self.tt = 0

    def enQueue(self, value: int) -> bool:
        if self.isFull(): return False
        self.q[self.tt] = value
        self.tt += 1
        if self.tt == len(self.q):
            self.tt = 0
        return True 

    def deQueue(self) -> bool:
        if self.isEmpty(): return False
        self.hh += 1
        if self.hh == len(self.q):
            self.hh = 0
        return True

    def Front(self) -> int:
        if self.isEmpty(): return -1
        return self.q[self.hh]

    def Rear(self) -> int:
        if self.isEmpty(): return -1
        t = self.tt - 1
        if t < 0: 
            t += len(self.q)
        return self.q[t]

    def isEmpty(self) -> bool:
        return self.hh == self.tt

    def isFull(self) -> bool:
        return (self.tt + 1) % len(self.q) == self.hh


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
