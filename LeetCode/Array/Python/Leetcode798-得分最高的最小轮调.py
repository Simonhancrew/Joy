class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        n = len(nums)
        b = [0] * (n + 1)
        for i in range(n):
            l,r = i - nums[i] + 1,i
            if l >= 0: 
                b[l] = b[l] + 1
                b[r + 1] = b[r + 1] - 1
            else:
                b[0],b[r + 1] = b[0] + 1,b[r + 1] - 1
                b[l + n],b[n] = b[l + n] + 1,b[n] - 1
        
        res,k,tot = int(1e6),-1,0

        for i in range(n):
            tot += b[i]
            if res > tot:
                res = tot
                k = i
        return k