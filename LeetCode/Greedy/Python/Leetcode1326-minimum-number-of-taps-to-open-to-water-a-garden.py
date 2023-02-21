class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        rec = []
        for (i, v) in enumerate(ranges):
            rec.append([i - v, i + v])
        rec.sort()
        i, res, r = 0, 0, 0
        while i < len(rec):
            j, mr = i, -1
            while j < len(rec) and rec[j][0] <= r:
                mr = max(mr, rec[j][1])
                j += 1
            if mr == -1: return -1
            res += 1
            if mr >= n:
                return res
            r, i = mr, j
        return -1
