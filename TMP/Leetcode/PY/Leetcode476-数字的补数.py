class Solution:
    def findComplement(self, num: int) -> int:
        cnt,x = 0,num
        while x != 0:
            cnt += 1
            x >>= 1
        return ~num & ((1 << cnt) - 1)