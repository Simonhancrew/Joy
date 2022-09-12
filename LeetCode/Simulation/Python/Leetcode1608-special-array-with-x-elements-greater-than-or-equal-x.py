class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        nums.reverse()
        n = len(nums)
        for i in range(1,n + 1):
            if nums[i - 1] >= i and (i == n or nums[i] < i):
                return i
        return -1