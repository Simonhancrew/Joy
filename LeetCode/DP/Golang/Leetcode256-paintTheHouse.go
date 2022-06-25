package sbgo

func minCost(costs [][]int) int {
	n := len(costs)
	f := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		f[i] = make([]int, 3)
	}
	for i := 1; i <= n; i++ {
		for j := 0; j < 3; j++ {
			if j == 0 {
				f[i][j] = min(f[i-1][1], f[i-1][2])
			}
			if j == 1 {
				f[i][j] = min(f[i-1][0], f[i-1][2])
			}
			if j == 2 {
				f[i][j] = min(f[i-1][1], f[i-1][0])
			}
			f[i][j] += costs[i-1][j]
		}
	}
	return min(f[n][0], min(f[n][1], f[n][2]))
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
