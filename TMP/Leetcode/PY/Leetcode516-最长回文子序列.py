class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for length in range(1,n + 1):
            for i in range(0,n + 1 - length):
                j = i + length - 1
                if(length == 1):
                    dp[i][j] = 1
                else:
                    if s[i] == s[j]:
                        dp[i][j] = dp[i + 1][j - 1] + 2
                    dp[i][j] = max(dp[i][j],max(dp[i + 1][j],dp[i][j - 1]))
        return dp[0][n - 1] 
