class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        nums.append(nums[-1] + 1)
        l,r = 0,len(nums) // 2 - 1
        while l < r:
            mid = l + r >> 1
            if nums[mid * 2] != nums[mid * 2 + 1]: r = mid
            else: l = mid + 1
        return nums[l << 1]