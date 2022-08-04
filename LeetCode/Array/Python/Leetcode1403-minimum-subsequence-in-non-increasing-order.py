class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort()
        n,acc,s = len(nums),0,sum(nums)
        ans = []
        for i in range(n - 1,-1,-1):
            if acc > s: break
            acc += nums[i]
            s -= nums[i]
            ans.append(nums[i])
        return ans
