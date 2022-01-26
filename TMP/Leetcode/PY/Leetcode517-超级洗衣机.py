from typing import List

class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        tot,n = sum(machines),len(machines)
        if tot % n != 0: return -1
        avg = tot // n
        l,r,ans = 0,tot,0
        for i in range(n):
            r -= machines[i]
            r2l = max(i * avg - l,0)
            l2r = max((n - i - 1) * avg - r,0)
            ans = max(ans,l2r + r2l)
            l += machines[i]
        return ans