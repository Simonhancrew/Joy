package sbgo

func soupServings(n int) float64 {
	n = (n + 24) / 25
	if n >= 200 {
		return 1.0
	}
	f := make([][]float64, n+1)
	max := func(i, j int) int {
		if i < j {
			return j
		}
		return i
	}
	gen := func(x int) int {
		return max(0, x)
	}
	for i := 0; i <= n; i++ {
		f[i] = make([]float64, n+1)
		for j := 0; j <= n; j++ {
			if i == 0 && j == 0 {
				f[i][j] = 0.5
			} else if i != 0 && j == 0 {
				f[i][j] = 0
			} else if i == 0 && j != 0 {
				f[i][j] = 1
			} else {
				f[i][j] = (f[gen(i-4)][j] + f[gen(i-3)][gen(j-1)] + f[gen(i-2)][gen(j-2)] + f[gen(i-1)][gen(j-3)]) / 4
			}
		}
	}
	return f[n][n]
}
