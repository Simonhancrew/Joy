class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        n = len(nums)
        f, ans = [0] * n, nums[0]
        f[0] = nums[0]
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                f[i] = f[i - 1] + nums[i]
            else:
                f[i] = nums[i]
            ans = f[i] if ans < f[i] else ans
        return ans
