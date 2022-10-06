class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        n, m = maxChoosableInteger, desiredTotal
        if (n + 1) * n // 2 < m: return False

        @cache
        def dp(x):
            tot = 0
            for i in range(n):
                if (x >> i) & 1 == 1: tot += i + 1
            for i in range(n):
                if (x >> i) & 1 == 1: continue
                if tot + i + 1 >= m: return True
                if not dp(x + (1 << i)): return True
            return False

        return dp(0)
