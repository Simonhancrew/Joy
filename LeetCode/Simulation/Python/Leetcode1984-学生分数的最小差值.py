class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans, n = int(1e9), len(nums)
        for i in range(0, n - k + 1):
            if nums[i + k - 1] - nums[i] < ans: ans = nums[i + k - 1] - nums[i]
        return ans
