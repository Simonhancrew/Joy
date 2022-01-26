class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        N = int(1e9)
        def check(a,b):
            mp1,mp2 = [0] * 10,[0] * 10
            while a != 0:
                t = a % 10
                a //= 10
                mp1[t] += 1
            while b != 0:
                t = b % 10
                b //= 10
                mp2[t] += 1
            return mp1==mp2
        i = 1
        while i <= N:
            if check(i,n):
                return True
            i *= 2
        return False