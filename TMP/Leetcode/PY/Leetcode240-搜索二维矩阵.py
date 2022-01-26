from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n,m = len(matrix),len(matrix[0])
        r,c = 0,m - 1
        while r < n and c >= 0:
            if matrix[r][c] > target: c -= 1
            elif matrix[r][c] < target: r += 1
            else: return True
        return False    