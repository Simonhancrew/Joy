class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res,n = 0,len(nums)
        for i in nums:
            res ^= i
        for i in range(0,n + 1):
            res ^= i
        return res