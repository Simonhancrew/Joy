class Solution:
    def countDigitOne(self, n: int) -> int:
        if n <= 0:
            return 0
        nums = []
        while n != 0:
            nums.append(n % 10)
            n //= 10
        nums.reverse()
        res = 0
        for i in range(len(nums)):
            cur = nums[i]
            left,right,p = 0,0,1
            for j in range(i):
                left = left * 10 + nums[j]
            for j in range(i + 1,len(nums)):
                right = right * 10 + nums[j]
                p *= 10
            if cur == 0:
                res += left * p
            elif cur == 1:
                res += left * p + right + 1
            else:
                res += (left + 1) * p
        return res