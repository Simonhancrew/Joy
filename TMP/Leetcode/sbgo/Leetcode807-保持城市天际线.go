package sbgo

func maxIncreaseKeepingSkyline(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	row, col := make([]int, n), make([]int, m)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			row[i] = max(row[i], grid[i][j])
			col[j] = max(col[j], grid[i][j])
		}
	}
	res := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			res += min(row[i], col[j]) - grid[i][j]
		}
	}
	return res
}
