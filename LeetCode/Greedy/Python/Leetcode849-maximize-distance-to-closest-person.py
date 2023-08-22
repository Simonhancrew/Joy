class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        x, y, n = -1, -1, len(seats)
        d = -1
        for i in range(n):
            if seats[i] == 1:
                if  y != -1:
                    d = max(d, i - y)
                if x == -1:
                    x = i
                y = i
        return max(d // 2, x, n - 1 - y)
