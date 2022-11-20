class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        f = [[0] * (query_row + 1) for _ in range(query_row + 1)]    
        f[0][0] = poured
        for i in range(query_row):
            for j in range(i + 1):
                if f[i][j] > 1:
                    x = (f[i][j] - 1) / 2
                    f[i + 1][j] += x
                    f[i + 1][j + 1] += x
        return min(1.0, f[query_row][query_glass]) 