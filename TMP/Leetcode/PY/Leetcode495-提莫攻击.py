from typing import List
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        res,last = 0,-1
        for x in timeSeries:
            t = x + duration - 1
            res += duration if last < x else t - last
            last = t
        return res