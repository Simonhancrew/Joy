class Solution:
    def sumSubseqWidths(self, nums: List[int]) -> int:
        P, n = int(1e9 + 7), len(nums)
        p = [0] * (n + 1)
        p[0] = 1
        for i in range(1, n + 1):
            p[i] = p[i - 1] * 2 % P
        nums.sort()
        res = 0
        for i in range(n):
            res = (res + nums[i] * p[i] - nums[i] * p[n - i - 1]) % P
        return res
