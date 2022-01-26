from typing import List
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return 0
        for i in range(n - 1,0,-1):
            nums[i] -= nums[i - 1]
        res,i = 0,1
        while i < n:
            j = i
            while j < n and nums[i] == nums[j]:
                j += 1
            k = j - i
            res += (k - 1) * k // 2
            i = j
        return res