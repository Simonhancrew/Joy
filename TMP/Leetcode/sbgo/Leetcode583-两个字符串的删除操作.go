package sbgo

func minDistance(word1 string, word2 string) int {
	n, m := len(word1), len(word2)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m+1)
	}
	for i := 0; i <= n; i++ {
		dp[i][0] = i
	}
	for i := 0; i <= m; i++ {
		dp[0][i] = i
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1
			if word1[i-1] == word2[j-1] {
				dp[i][j] = min(dp[i-1][j-1], dp[i][j])
			}
		}
	}
	return dp[n][m]
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
