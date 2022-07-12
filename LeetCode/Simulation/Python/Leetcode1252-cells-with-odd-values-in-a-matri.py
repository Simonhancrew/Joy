class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        row,col = [0] * m,[0] * n
        for r,c in indices:
            row[r] += 1
            col[c] += 1

        cnt = 0
        for i in range(m):
            for j in range(n):  
                if (row[i] + col[j]) & 1: cnt += 1
        return cnt