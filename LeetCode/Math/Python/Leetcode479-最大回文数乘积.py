class Solution:
    def largestPalindrome(self, n: int) -> int:
        if n == 1: return 9
        base = (10 ** n) - 1
        for i in range(base,-1,-1):
            p,x = i,i
            while x != 0:
                p = p * 10 + x % 10
                x //= 10
            x = base
            while x >= p // x:
                if p % x == 0:
                    return p % 1337
                x -= 1 