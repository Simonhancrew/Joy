class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        for x in cuboids:
            x.sort()
        cuboids.sort(reverse=True)
        n, res = len(cuboids), 0
        f = [0] * n
        for i in range(n):
            f[i] = cuboids[i][2]
            for j in range(i):
                if not False in [cuboids[j][k] >= cuboids[i][k] for k in range(3)]:
                    f[i] = max(f[i], f[j] + cuboids[i][2])
            res = max(res, f[i])
        return res