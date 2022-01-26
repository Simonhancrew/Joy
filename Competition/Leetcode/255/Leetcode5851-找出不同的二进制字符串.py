from typing import List

class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        off = 1 << n
        for i in range(off):
            cur = bin(i)
            cur = str(cur)[2:]
            while len(cur) < n:
                cur = '0' + cur 
            if cur not in nums:
                return cur  