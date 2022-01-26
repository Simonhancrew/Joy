from typing import List
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        cnt = 0
        f1 = f2 = f3 = int(-1e10)
        for i in nums:
            if i > f3: 
                cnt += 1
                f1,f2,f3 = f2,f3,i
            elif i < f3 and i > f2:
                cnt += 1
                f1,f2 = f2,i
            elif i < f2 and i > f1:
                cnt += 1
                f1 = i
        res = f3 if cnt < 3 else f1
        return res