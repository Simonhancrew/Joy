class Solution:
    def findLHS(self, nums: List[int]) -> int:
        nums.sort()
        l,r,res = 0,0,0
        while r < len(nums):
            while nums[r] - nums[l] > 1: l += 1
            if nums[r] - nums[l] == 1:
                res = max(res,r - l + 1)
            r += 1
        return res