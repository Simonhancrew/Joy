class Solution:
    def __init__(self):
        self.primes = []
        self.st = [False] * 34
        self.get_prime(33)

    def get_prime(self,n):
        self.st[1] = True
        for i in range(2,n + 1):
            if not self.st[i]:
                self.primes.append(i)
            j = 0
            while self.primes[j] < n // i :
                self.st[self.primes[j] * i] = True
                if i % self.primes[j] == 0:
                    break
                j += 1
    
    def check(self,n):
        cnt = 0
        while n != 0:
            n -= (n & -n)
            cnt += 1
        return not self.st[cnt]

    def countPrimeSetBits(self, left: int, right: int) -> int:
        ans = 0
        for i in range(left,right + 1):
            if self.check(i): ans += 1
        return ans