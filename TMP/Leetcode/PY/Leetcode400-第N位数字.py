class Solution:
    def findNthDigit(self, n: int) -> int:
        idx,base,s = 1,9,1
        while n > base * idx:
            n -= base * idx
            base *= 10
            s *= 10
            idx += 1
        s += (n + idx - 1) // idx - 1
        n = n % idx if n % idx != 0 else idx
        return ord(str(s)[n - 1]) - ord('0')