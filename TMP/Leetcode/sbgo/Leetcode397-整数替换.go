package sbgo

func integerReplacement(n int) int {
	f := map[int]int{}
	var dp func(int) int
	dp = func(n int) int {
		if _, ok := f[n]; ok {
			return f[n]
		}
		if n == 1 {
			return 0
		}
		if n%2 == 0 {
			f[n] = dp(n/2) + 1
			return f[n]
		}
		f[n] = min(dp(n+1), dp(n-1)) + 1
		return f[n]
	}
	return dp(n)
}
