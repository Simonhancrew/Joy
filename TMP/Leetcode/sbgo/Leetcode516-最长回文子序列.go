package sbgo

func longestPalindromeSubseq(s string) int {
	n := len(s)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
	}
	for length := 1; length <= n; length++ {
		for i := 0; i+length-1 < n; i++ {
			j := i + length - 1
			if length == 1 {
				dp[i][j] = 1
			} else {
				if s[i] == s[j] {
					dp[i][j] = dp[i+1][j-1] + 2
				}
				dp[i][j] = max(dp[i][j], max(dp[i+1][j], dp[i][j-1]))
			}
		}
	}
	return dp[0][n-1]
}
