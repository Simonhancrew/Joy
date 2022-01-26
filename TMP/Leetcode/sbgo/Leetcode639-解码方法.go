package sbgo

func numDecodings(s string) int {
	n := len(s)
	dp := make([]int, n+1)
	dp[0] = 1
	const MOD int = 1e9 + 7
	for i := 1; i <= n; i++ {
		for j := 1; j <= 26; j++ {
			a := s[i-1]
			if j <= 9 {
				if a == '*' || int(a-'0') == j {
					dp[i] += dp[i-1]
				}
			} else if i >= 2 {
				x, y := j/10, j%10
				b := s[i-2]
				if (int(b-'0') == x || b == '*' && x != 0) && (int(a-'0') == y || a == '*' && y != 0) {
					dp[i] += dp[i-2]
				}
			}
		}
		dp[i] %= MOD
	}
	return dp[n]
}
