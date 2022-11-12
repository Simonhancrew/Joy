package sbgo

func numTilings(n int) int {
	w := [][]int{{1, 1, 1, 1}, {0, 0, 1, 1}, {0, 1, 0, 1}, {1, 0, 0, 0}}
	f := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		f[i] = make([]int, 4)
	}
	P := int(1e9 + 7)
	f[0][0] = 1
	for i := 0; i < n; i++ {
		for j := 0; j < 4; j++ {
			for k := 0; k < 4; k++ {
				f[i+1][k] = (f[i+1][k] + f[i][j]*w[j][k]) % P
			}
		}
	}
	return f[n][0]
}
