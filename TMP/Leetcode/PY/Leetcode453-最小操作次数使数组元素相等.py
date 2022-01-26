from typing import List
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        m,res= min(nums),0
        for i in nums:
            res += i - m
        return res