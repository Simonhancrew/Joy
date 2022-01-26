class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        p = 1337        
        def qmi(a,b):
            a %= p
            res = 1
            while b != 0:
                if b & 1 == 1: res = res * a % p 
                b >>= 1
                a = a * a % p
            return res
        if not b: return 1
        k = b[-1]
        b.pop()
        return qmi(self.superPow(a,b),10) * qmi(a,k) % p
