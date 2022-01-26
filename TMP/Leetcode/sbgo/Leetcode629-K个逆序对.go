package sbgo

func kInversePairs(n int, k int) int {
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	f[1][0] = 1
	const mod = 1e9 + 7
	for i := 2; i <= n; i++ {
		s := 0
		for j := 0; j <= k; j++ {
			s += f[i-1][j]
			if j >= i {
				s -= f[i-1][j-i]
			}
			f[i][j] = s % mod
		}
	}
	return f[n][k]
}
