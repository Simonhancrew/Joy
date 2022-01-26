class Solution:
    def findIntegers(self, n: int) -> int:
        dp = [[0] * 2 for _ in range(33)]
        num = []
        while n != 0:
            num.append(n & 1)
            n >>= 1

        dp[1][0] = dp[1][1] = 1
        for i in range(2,len(num) + 1):
            dp[i][0] = dp[i - 1][1] + dp[i - 1][0]
            dp[i][1] = dp[i - 1][0]

        res,last = 0,0
        for i in range(len(num),0,-1):
            if num[i - 1] == 1:
                res += dp[i][0]
                if last == 1:
                    return res
            last = num[i - 1]
        
        return res + 1