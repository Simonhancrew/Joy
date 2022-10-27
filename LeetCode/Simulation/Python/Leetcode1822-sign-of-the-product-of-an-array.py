class Solution:
    def arraySign(self, nums: List[int]) -> int:
        nag, n = 0, len(nums)
        for i in range(n):
            if nums[i] == 0: return 0
            if nums[i] < 0: nag += 1
        return -1 if nag % 2 == 1 else 1