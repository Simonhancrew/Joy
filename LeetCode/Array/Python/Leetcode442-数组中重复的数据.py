class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans, n = [], len(nums)
        for i in range(n):
            x = abs(nums[i])
            if nums[x - 1] > 0:
                nums[x - 1] = -nums[x - 1]
            else:
                ans.append(x)
        return ans
