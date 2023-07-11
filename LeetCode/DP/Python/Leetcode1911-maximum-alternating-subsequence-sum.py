class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)
        f = [[-100] * 2 for _ in range(n)]
        f[0][0], f[0][1] = nums[0], 0
        for i in range(1, n):
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + nums[i])
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - nums[i])
        return max(f[n - 1][0], f[n - 1][1])