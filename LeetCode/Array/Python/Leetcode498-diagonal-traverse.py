class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        ans, m, n = [], len(mat[0]), len(mat)
        for i in range(n + m - 1):
            if i % 2 == 1:
                x = 0 if i < m else i - m + 1
                y = i if i < m else m - 1
                while x < n and y >= 0:
                    ans.append(mat[x][y])
                    x += 1
                    y -= 1
            else:
                x = i if i < n else n - 1
                y = 0 if i < n else i - n + 1
                while x >= 0 and y < m:
                    ans.append(mat[x][y])
                    x -= 1
                    y += 1
        return ans
