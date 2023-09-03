class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        n = len(dist)
        rec = [0] * n
        for i in range(n):
            rec[i] = (dist[i] + speed[i] - 1) // speed[i]
        rec.sort()
        for i in range(n):
            if rec[i] <= i:
                return i
        return n