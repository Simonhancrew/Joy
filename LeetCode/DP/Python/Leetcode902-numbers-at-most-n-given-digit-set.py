class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        s = str(n)
        m = len(s)
        f = [-1] * m
        @cache
        def dfs(idx, lead, limit):
            if idx == m: return 1 if not lead else 0
            res = 0
            if lead:
                res = dfs(idx + 1, True, False)
            up = '9' if not limit else s[idx]
            for d in digits:
                if d > up:break
                res += dfs(idx + 1, False, limit and d == s[idx])
            return res
        return dfs(0, True, True)