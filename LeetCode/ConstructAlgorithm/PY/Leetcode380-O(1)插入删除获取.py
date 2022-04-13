class RandomizedSet:

    def __init__(self):
        self.mp = defaultdict()
        self.nums = []

    def insert(self, val: int) -> bool:
        if val in self.mp:
            return False
        self.nums.append(val)
        self.mp[val] = len(self.nums) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.mp:
            return False
        tar = self.nums[-1]
        px,py = self.mp[val],self.mp[tar]
        self.nums[px],self.nums[py] = self.nums[py],self.nums[px]
        self.mp[val],self.mp[tar] = self.mp[tar],self.mp[val]
        self.nums.pop(-1)
        del self.mp[val]
        return True

    def getRandom(self) -> int:
        idx = randint(0,len(self.nums) - 1)
        return self.nums[idx]
