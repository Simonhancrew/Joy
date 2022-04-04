class NumArray:

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.nums = nums
        self.tr = [0] * (self.n + 1)
        for i in range(self.n):
            self.add(i + 1,nums[i])
    
    def lowbit(self,x):
        return x & -x

    def add(self,x,k):
        while x <= self.n:
            self.tr[x] += k
            x += self.lowbit(x)

    def ask(self,x):
        tot = 0
        while x > 0:
            tot += self.tr[x]
            x -= self.lowbit(x)
        return tot

    def update(self, index: int, val: int) -> None:
        pre = self.ask(index + 1) - self.ask(index)
        ch = val - pre
        self.add(index + 1,ch)

    def sumRange(self, left: int, right: int) -> int:
        return self.ask(right + 1) - self.ask(left)