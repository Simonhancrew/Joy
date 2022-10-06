class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        f0, f1 = 0, 0
        for c in s:
            ff0, ff1 = f0, min(f1, f0)
            ff0 += 1 if c == '1' else 0
            ff1 += 1 if c == '0' else 0
            f0, f1 = ff0, ff1
        return min(f0, f1)
