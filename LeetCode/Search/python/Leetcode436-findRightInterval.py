class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        res = [-1] * n
        for i in range(n):
            intervals[i].append(i)
        intervals.sort()
        for x in intervals:
            l,r = 0,n - 1
            while l < r:
                mid = l + r >> 1
                if intervals[mid][0] >= x[1]: r = mid
                else: l = mid + 1
            if intervals[l][0] >= x[1]:
                res[x[2]] = intervals[l][2]
        return res