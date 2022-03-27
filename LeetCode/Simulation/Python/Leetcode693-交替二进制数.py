class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        pre = n & 1
        n >>= 1
        while n != 0:
            if pre == n & 1: return False
            pre = n & 1
            n >>= 1
        return True