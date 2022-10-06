class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        n = len(target)

        @cache
        def dp(st):
            if st == (1 << n) - 1: return 0
            res = 20
            for s in stickers:
                t, cnt = st, Counter(s)
                for i, c in enumerate(target):
                    if not (t >> i) & 1 and cnt[c]:
                        cnt[c] -= 1
                        t += 1 << i
                if t != st:
                    res = min(res, dp(t) + 1)
            return res

        res = dp(0)
        return res if res != 20 else -1
