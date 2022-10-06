class Solution:
    def preimageSizeFZF(self, k: int) -> int:
        def f(x):
            res = 0
            while x:
                res += (x // 5)
                x //= 5
            return res

        def calcu(k):
            l, r = -1, int(1e18)
            while l < r:
                mid = (l + r + 1) >> 1
                if f(mid) <= k: l = mid
                else: r = mid - 1
            return r

        return calcu(k) - calcu(k - 1)
