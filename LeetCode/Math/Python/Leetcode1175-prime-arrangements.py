class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        st, primes, MOD = [False] * (n + 1), [], int(1e9 + 7)

        def fact(n):
            res = 1
            for i in range(1, n + 1):
                res = res * i % MOD
            return res

        for i in range(2, n + 1):
            if not st[i]: primes.append(i)
            j = 0
            while primes[j] * i <= n:
                st[primes[j] * i] = True
                if i % primes[j] == 0: break
                j += 1
        cnt = len(primes)
        # print(fact(n - cnt))
        return fact(n - cnt) * fact(cnt) % MOD
