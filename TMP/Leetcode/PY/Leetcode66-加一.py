from typing import List
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n,car = len(digits),1
        for i in range(n - 1,-1,-1):
            cur = car + digits[i]
            digits[i] = cur % 10
            car = cur // 10
        if car:
            digits.insert(0,1)
        return digits