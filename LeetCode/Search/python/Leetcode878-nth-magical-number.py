class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        MOD = int(1e9) + 7
        l, r = 0, int(4e13)
        def gcd(a, b):
            return a if b == 0 else gcd(b, a % b)
        def get(tar, a, b):
            return tar // a + tar // b - tar // (a * b // gcd(a, b))
        while l < r: 
            mid = l + r >> 1
            if get(mid, a, b) >= n: r = mid
            else: l = mid + 1
        return l  % MOD