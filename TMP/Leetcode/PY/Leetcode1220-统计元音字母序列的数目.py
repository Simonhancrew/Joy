class Solution:
    def countVowelPermutation(self, n: int) -> int:
        f = [[0] * 5 for _ in range(n + 1)]
        P = int(1e9 + 7)
        for i in range(5): f[1][i] = 1
        for i in range(2,n + 1):
            f[i][0] = f[i - 1][1]
            f[i][1] = f[i - 1][0] + f[i - 1][2]
            f[i][2] = f[i - 1][0] + f[i - 1][1] + f[i - 1][3] + f[i - 1][4]
            f[i][3] = f[i - 1][2] + f[i - 1][4]
            f[i][4] = f[i - 1][0]
            for j in range(5): f[i][j] %= P
        ans = 0
        for i in range(5): ans += f[n][i]
        return ans % P