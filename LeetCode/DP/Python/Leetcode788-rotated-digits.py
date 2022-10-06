class Solution:
    def rotatedDigits(self, n: int) -> int:
        diffs = [0, 0, 1, -1, -1, 1, 1, -1, 0, 1]
        s = str(n)
        f = [[-1] * 2 for _ in range(len(s))]

        # maybe cache is better
        def dfs(pos, diff, limit):
            if pos == len(s):
                return diff
            if not limit and f[pos][diff] != -1:
                return f[pos][diff]
            res = 0
            up = ord(s[pos]) - ord('0') if limit else 9
            for i in range(0, up + 1):
                if diffs[i] == -1:
                    continue
                res += dfs(pos + 1, diff or diffs[i], limit and i == up)
            if not limit:
                f[pos][diff] = res
            return res

        return dfs(0, False, True)
