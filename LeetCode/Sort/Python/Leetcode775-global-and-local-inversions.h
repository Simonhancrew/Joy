class Solution:
    def isIdealPermutation(self, nums: List[int]) -> bool:
        lmin, n = nums[-1], len(nums)
        for i in range(n - 2, 0, -1):
            if nums[i - 1] > lmin:
                return False
            lmin = min(lmin, nums[i])
        return True
