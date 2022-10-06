class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n, m, ans = len(grid), len(grid[0]), copy.deepcopy(grid)
        for _ in range(k):
            for i in range(n):
                for j in range(1, m):
                    ans[i][j] = grid[i][j - 1]

            t = grid[n - 1][m - 1]
            for i in range(1, n):
                ans[i][0] = grid[i - 1][m - 1]
            ans[0][0] = t
            grid = copy.deepcopy(ans)
        return ans
