package sbgo

func cherryPickup(grid [][]int) int {
	n := len(grid)
	f := make([][][]int, n+1)
	for i := 0; i <= n; i++ {
		f[i] = make([][]int, n+1)
		for j := 0; j <= n; j++ {
			f[i][j] = make([]int, 2*n+1)
			for k := 0; k <= 2*n; k++ {
				f[i][j][k] = -10000
			}
		}
	}
	f[1][1][2] = grid[0][0]
	for k := 3; k <= 2*n; k++ {
		for i := max(1, k-n); i <= min(n, k-1); i++ {
			for j := max(1, k-n); j <= min(n, k-1); j++ {
				if grid[i-1][k-i-1] == -1 || grid[j-1][k-j-1] == -1 {
					continue
				}
				t := grid[i-1][k-i-1]
				if i != j {
					t += grid[j-1][k-j-1]
				}
				for a := i - 1; a <= i; a++ {
					for b := j - 1; b <= j; b++ {
						f[i][j][k] = max(f[i][j][k], f[a][b][k-1]+t)
					}
				}
			}
		}
	}
	return max(0, f[n][n][2*n])
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
