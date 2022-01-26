class Solution:
    def arrangeCoins(self, n: int) -> int:
        l,r = 0,n
        while l < r:
            mid = (l + r + 1) >> 1
            tot = (mid + 1) * mid // 2
            if tot <= n: l = mid
            else: r = mid - 1
        return l