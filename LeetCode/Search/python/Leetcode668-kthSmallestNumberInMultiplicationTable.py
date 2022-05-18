class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        l,r = 1,m * n
        def check(mid,m,n):
            res = 0
            for i in range(1,n + 1):
                res += min(m,mid // i)
            return res
        while l < r:
            mid = (l + r) // 2
            if check(mid,m,n) >= k: r = mid
            else: l = mid + 1
        return l