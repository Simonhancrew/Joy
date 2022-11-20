package sbgo

func champagneTower(poured int, query_row int, query_glass int) float64 {
	f := make([][]float64, query_row+1)
	for i := 0; i < query_row+1; i++ {
		f[i] = make([]float64, query_row+1)
	}
	min := func(i, j float64) float64 {
		if i < j {
			return i
		}
		return j
	}
	f[0][0] = float64(poured)
	for i := 0; i < query_row; i++ {
		for j := 0; j <= i; j++ {
			if f[i][j] > 1 {
				x := (f[i][j] - 1) / 2
				f[i+1][j], f[i+1][j+1] = f[i+1][j]+x, f[i+1][j+1]+x
			}
		}
	}
	return min(1.0, f[query_row][query_glass])
}
