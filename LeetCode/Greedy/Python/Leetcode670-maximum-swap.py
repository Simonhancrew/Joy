class Solution:
    def maximumSwap(self, num: int) -> int:
        rec = []
        while num:
            rec.append(num % 10)
            num //= 10
        n = len(rec)
        for i in range(n - 1,-1,-1):
            rmx,idx = rec[i],i
            for j in range(i - 1,-1,-1):
                if rec[j] >= rmx: 
                    rmx = rec[j]
                    idx = j
            if rmx > rec[i]:
                rec[i],rec[idx] = rec[idx],rec[i]
                break
        ans = 0
        for i in range(n - 1,-1,-1):
            ans = ans * 10 + rec[i]
        return ans
