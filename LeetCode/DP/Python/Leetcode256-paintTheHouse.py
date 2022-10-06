class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        n = len(costs)
        f = [[0] * 3 for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(3):
                if j == 0:
                    f[i][j] = min(f[i - 1][2], f[i - 1][1])
                if j == 1:
                    f[i][j] = min(f[i - 1][2], f[i - 1][0])
                if j == 2:
                    f[i][j] = min(f[i - 1][1], f[i - 1][0])
                f[i][j] += costs[i - 1][j]
        return min(f[n][0], f[n][1], f[n][2])
