package sbgo

func getMaximumGold(grid [][]int) int {
	n, m, ans := len(grid), len(grid[0]), 0
	dx, dy := []int{0, -1, 0, 1}, []int{-1, 0, 1, 0}
	var dfs func(x, y, beg int)
	dfs = func(x, y, beg int) {
		beg += grid[x][y]
		if beg > ans {
			ans = beg
		}
		rec := grid[x][y]
		grid[x][y] = 0
		for i := 0; i < 4; i++ {
			nx, ny := x+dx[i], y+dy[i]
			if nx < 0 || nx >= n || ny < 0 || ny >= m {
				continue
			}
			if grid[nx][ny] == 0 {
				continue
			}
			dfs(nx, ny, beg)
		}
		grid[x][y] = rec
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] != 0 {
				dfs(i, j, 0)
			}
		}
	}
	return ans
}
