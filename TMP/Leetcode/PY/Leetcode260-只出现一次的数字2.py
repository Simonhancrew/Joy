from typing import List

# 位运算，找到不一样的位分别处理就行了
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        mask = 0
        for num in nums:
            mask ^= num
        diff = 1
        while (diff & mask) == 0:
            diff <<= 1
        a,b = 0,0
        for num in nums:
            if (num & diff) != 0:
                a ^= num
            else:
                b ^= num
        return [a,b]
