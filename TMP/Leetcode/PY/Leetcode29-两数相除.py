class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        a = -dividend if dividend < 0 else dividend
        b = -divisor if divisor < 0 else divisor
        sign = -1 if (dividend ^ divisor) < 0 else 1
        l,r = 0,a
        def mul(mid,b):
            ans = 0
            while b != 0:
                if (b & 1) == 1:
                    ans += mid
                mid += mid
                b >>= 1
            return ans
        while l < r:
            mid = l + r + 1 >> 1
            if mul(mid,b) <= a: l = mid
            else: r = mid - 1
        if sign == -1: l = -l
        if l > (1 << 31) - 1 or l < -(1 << 31):
            l = (1 << 31) - 1
        return l