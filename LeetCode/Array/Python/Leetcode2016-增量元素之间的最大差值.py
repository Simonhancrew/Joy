class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ans,n,mn = -1,len(nums),nums[0]
        for i in range(1,n):
            if nums[i] > mn: ans = max(ans,nums[i] - mn)
            else: mn = nums[i]
        return ans