from typing import List
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        c1 = c2 = r1 = r2 = 0
        n = len(nums)
        for x in nums:
            if r1 != 0 and x == c1: r1 += 1
            elif r2 != 0 and x == c2: r2 += 1
            elif r1 == 0: c1,r1 = x,1
            elif r2 == 0: c2,r2 = x,1
            else: r1,r2 = r1 - 1,r2 - 1
        r1,r2 = 0,0
        for x in nums:
            if x == c1: r1 += 1
            elif x == c2: r2 += 1
        ans = []
        if r1 > n // 3:
            ans.append(c1)
        if r2 > n // 3:
            ans.append(c2)
        return ans 