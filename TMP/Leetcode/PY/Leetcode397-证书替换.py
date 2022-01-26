class Solution:
    def integerReplacement(self, n: int) -> int:
        f = defaultdict(int)
        def dp(n):
            if n in f: return f[n]
            if n == 1: return 0
            if n % 2 == 0:
                f[n] = dp(n / 2) + 1
                return f[n]
            f[n] = min(dp(n + 1),dp(n - 1)) + 1
            return f[n]
        return dp(n)