class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        res, n = 0, len(nums)
        for i in range(n):
            mx, mn = nums[i], nums[i]
            for j in range(i + 1, n):
                mx = max(mx, nums[j])
                mn = min(mn, nums[j])
                res += mx - mn
        return res
