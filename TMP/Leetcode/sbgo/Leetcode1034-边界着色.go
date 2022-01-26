package sbgo

func colorBorder(grid [][]int, row int, col int, color int) [][]int {
	n, m := len(grid), len(grid[0])
	st := make([][]int, n)
	for i := range st {
		st[i] = make([]int, m)
	}
	var dfs func(int, int)
	dx, dy := []int{0, 1, 0, -1}, []int{1, 0, -1, 0}
	dfs = func(x, y int) {
		is_bd := false
		for i := 0; i < 4; i++ {
			a, b := dx[i]+x, dy[i]+y
			if a >= 0 && a < n && b >= 0 && b < m && grid[x][y] == grid[a][b] {
				if st[a][b] == 0 {
					st[a][b] = 1
					dfs(a, b)
				}
			} else {
				is_bd = true
			}
		}
		if is_bd {
			st[x][y] = 2
		}
	}
	st[row][col] = 1
	dfs(row, col)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if st[i][j] == 2 {
				grid[i][j] = color
			}
		}
	}
	return grid
}
