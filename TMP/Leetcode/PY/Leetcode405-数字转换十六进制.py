class Solution:
    def toHex(self, num: int) -> str:
        if not num: return '0'
        rec = '0123456789abcdef'
        off,mod = 0,0xf
        ans = ''
        while num and off < 8:
            t = num & mod
            ans = rec[t] + ans
            num >>= 4
            off += 1
        return ans
