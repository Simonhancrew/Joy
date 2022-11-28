class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        n = len(nums)
        s, f = [0] * (n + 1), [[-1000000] * (k + 1) for _ in range(n + 1)]
        for i in range(1, n + 1): s[i] = s[i - 1] + nums[i - 1]
        f[0][0] = 0
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                for q in range(i):
                    f[i][j] = max(f[i][j], f[q][j - 1] + (s[i] - s[q]) / (i - q))
        return f[n][k]