class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        MOD = int(1e9 + 7)
        for i in range(1,n + 1):
            for j in range(1,27):
                a = s[i - 1]
                if j <= 9:
                    if a == '*' or a == chr(48 + j):
                        dp[i] += dp[i - 1]
                elif i >= 2:
                    b = s[i - 2]
                    x,y = j // 10,j % 10
                    if (b == chr(48 + x) or b == '*' and x > 0) and (a == chr(48 + y) or a == '*' and y > 0):
                        dp[i] += dp[i - 2]
            dp[i] %= MOD
        return dp[n]