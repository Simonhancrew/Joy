class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rec = rects
        self.s = [0]
        for x in rects:
            dx = x[2] - x[0] + 1
            dy = x[3] - x[1] + 1
            self.s.append(self.s[-1] + dx * dy)

    def pick(self) -> List[int]:
        n = len(self.rec)
        tar = random.randint(1,self.s[-1])
        l,r = 1,n
        while l < r:
            mid = (l + r) >> 1
            if self.s[mid] >= tar: r = mid
            else: l = mid + 1
        t = self.rec[r - 1]
        dx = t[2] - t[0] + 1
        dy = t[3] - t[1] + 1
        return [randrange(0,dx) + t[0],randrange(0,dy) + t[1]]