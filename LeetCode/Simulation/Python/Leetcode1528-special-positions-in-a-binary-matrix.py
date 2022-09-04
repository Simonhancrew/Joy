class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        n,m = len(mat),len(mat[0])
        r,c = [0] * n, [0] * m
        for i in range(n):
            for j in range(m):
                r[i] += mat[i][j]
                c[j] += mat[i][j]
        ans = 0
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 1 and r[i] == c[j] == 1:
                    ans += 1
        return ans