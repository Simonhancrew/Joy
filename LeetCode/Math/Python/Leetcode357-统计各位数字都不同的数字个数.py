class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0: return 1
        if n == 1: return 10
        base, mul, res = 9, 9, 10
        for i in range(n - 1):
            base *= (mul - i)
            res += base
        return res
