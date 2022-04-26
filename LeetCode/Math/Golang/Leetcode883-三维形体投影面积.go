package sbgo

func projectionArea(grid [][]int) int {
	n, l, r, d := len(grid), 0, 0, 0
	for i := 0; i < n; i++ {
		tl, tr := 0, 0
		for j := 0; j < n; j++ {
			if grid[i][j] != 0 {
				d++
			}
			tl = max(tl, grid[i][j])
			tr = max(tr, grid[j][i])
		}
		l += tl
		r += tr
	}
	return l + r + d
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
