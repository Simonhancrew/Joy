class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        f = [1,1]
        while f[-1] < k: f.append(f[-1] + f[-2])
        cnt,idx = 0,len(f) - 1
        while k:
            while f[idx] <= k:
                k -= f[idx]
                cnt += 1
            idx -= 1
        return cnt     