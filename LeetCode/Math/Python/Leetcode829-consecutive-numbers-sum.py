class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        n, res = n * 2, 0
        b = 1
        while b <= n // b:
            if n % b == 0:
                if (n // b - b + 1) % 2 == 0:
                    res += 1
            b += 1
        return res
