class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        n, m = len(img), len(img[0])
        res = [[0] * m for _ in range(n)]

        def get(x, y):
            acc, div = 0, 0
            for i in range(-1, 2):
                for j in range(-1, 2):
                    nx, ny = x + i, y + j
                    if nx < 0 or nx >= n or ny < 0 or ny >= m:
                        continue
                    acc += img[nx][ny]
                    div += 1
            return acc // div

        for i in range(n):
            for j in range(m):
                res[i][j] = get(i, j)
        return res
