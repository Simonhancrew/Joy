package sbgo

func getMoneyAmount(n int) int {
	f := make([][]int, n+2)
	for i := range f {
		f[i] = make([]int, n+2)
	}
	for len := 2; len <= n; len++ {
		for l := 1; l+len-1 <= n; l++ {
			r := l + len - 1
			f[l][r] = int(1e9)
			for k := l; k <= r; k++ {
				f[l][r] = min(f[l][r], max(f[l][k-1], f[k+1][r])+k)
			}
		}
	}
	return f[1][n]
}
