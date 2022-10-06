class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        res, acc, i, n = 0, 1, 0, len(nums)
        for j in range(n):
            acc *= nums[j]
            while i <= j and acc >= k:
                acc //= nums[i]
                i += 1
            res += j - i + 1
        return res
