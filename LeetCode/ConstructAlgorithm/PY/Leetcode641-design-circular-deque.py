class MyCircularDeque:
    def __init__(self, k: int):
        self.hh = self.tt = 0
        self.buf = [0] * (k + 1)

    def get(self, x):
        n = len(self.buf)
        return (x + n) % n

    def insertFront(self, value: int) -> bool:
        if self.isFull(): return False
        self.hh = self.get(self.hh - 1)
        self.buf[self.hh] = value
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull(): return False
        self.buf[self.tt] = value
        self.tt = self.get(self.tt + 1)
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty(): return False
        self.hh = self.get(self.hh + 1)
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty(): return False
        self.tt = self.get(self.tt - 1)
        return True

    def getFront(self) -> int:
        if self.isEmpty(): return -1
        return self.buf[self.hh]

    def getRear(self) -> int:
        if self.isEmpty(): return -1
        return self.buf[self.get(self.tt - 1)]

    def isEmpty(self) -> bool:
        return self.hh == self.tt

    def isFull(self) -> bool:
        return self.get(self.tt + 1) == self.hh
