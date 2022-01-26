class TopVotedCandidate:
    def __init__(self, persons: List[int], times: List[int]):
        n = len(persons)
        self.win = [0] * n
        self.time = times
        ss = [0] * n
        maxc ,maxp = 0,-1
        for i in range(n):
            p = persons[i]
            ss[p] += 1
            if ss[p] >= maxc:
                maxc = ss[p]
                maxp = p
            self.win[i] = maxp

    def q(self, t: int) -> int:
        l,r = 0,len(self.win) - 1
        while l < r:
            mid = (l + r + 1) // 2
            if self.time[mid] <= t: l = mid
            else: r = mid - 1
        return self.win[l]
