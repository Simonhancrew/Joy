class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m,suma = len(rolls),sum(rolls)
        sumb = (m + n) * mean - suma
        ev,lf = sumb // n,sumb % n
        if ev < 1 or ev > 6: return []
        if ev == 6 and lf > 0: return []
        res = [ev] * n
        for i in range(lf):
            res[i] += 1
        return res