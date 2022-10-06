class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        ans, i, j, n = 0, 0, 0, len(nums)
        nums.sort()
        while i < n:
            while i < n - 1 and nums[i + 1] == nums[i]:
                i += 1
            while j < i and nums[i] - nums[j] > k:
                j += 1
            if j < i and nums[i] - nums[j] == k: ans += 1
            i += 1
        return ans
