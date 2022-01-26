from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        l,r = 0,len(matrix) - 1
        
        def rotatecircle(m,l,r):
            off = r - l
            for i in range(off):
                m[l][l + i],m[l + i][r],m[r][r - i],m[r - i][l] = m[r - i][l],m[l][l + i],m[l + i][r],m[r][r - i]
        
        while l < r:
            rotatecircle(matrix,l,r)
            l += 1
            r -= 1