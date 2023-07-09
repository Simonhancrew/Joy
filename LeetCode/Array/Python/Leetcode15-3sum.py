class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        nums.sort()
        for i in range(0, n - 2):
            if i > 0 and nums[i - 1] == nums[i]: continue
            j, k = i + 1, n - 1
            while j < k:
                # print(j, k)
                if j > i + 1 and nums[j] == nums[j - 1]: 
                    j += 1  
                    continue
                while j < k - 1 and nums[i] + nums[j] + nums[k] > 0: k -= 1
                if nums[i] + nums[j] + nums[k] == 0:
                    ans.append([nums[i], nums[j], nums[k]])
                j += 1
        return ans