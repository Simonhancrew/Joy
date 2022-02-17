package sbgo

func knightProbability(n int, k int, row int, column int) float64 {
	f := make([][][]float64, n)
	for i := 0; i < n; i++ {
		f[i] = make([][]float64, n)
		for j := 0; j < n; j++ {
			f[i][j] = make([]float64, k+1)
		}
	}
	dx, dy := []int{-2, -1, 1, 2, 2, 1, -1, -2}, []int{1, 2, 2, 1, -1, -2, -2, -1}
	for st := 0; st <= k; st++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if st == 0 {
					f[i][j][0] = 1
				} else {
					for d := 0; d < 8; d++ {
						ni, nj := i+dx[d], j+dy[d]
						if ni < 0 || ni >= n || nj < 0 || nj >= n {
							continue
						}
						f[i][j][st] += f[ni][nj][st-1] / 8
					}
				}
			}
		}
	}
	return f[row][column][k]
}
