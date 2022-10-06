class Solution:
    def binaryGap(self, n: int) -> int:
        res, cur, pre = 0, 0, -1
        while n != 0:
            if n & 1 == 1:
                if pre != -1:
                    res = max(res, cur - pre)
                pre = cur
            n >>= 1
            cur += 1
        return res
