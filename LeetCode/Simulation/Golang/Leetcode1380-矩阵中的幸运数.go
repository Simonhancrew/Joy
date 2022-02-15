package sbgo

func luckyNumbers(matrix [][]int) []int {
	n, m := len(matrix), len(matrix[0])
	row, col := make([]int, n), make([]int, m)
	for i := 0; i < n; i++ {
		row[i] = int(1e5)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if row[i] > matrix[i][j] {
				row[i] = matrix[i][j]
			}
			if col[j] < matrix[i][j] {
				col[j] = matrix[i][j]
			}
		}
	}
	ans := []int{}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if matrix[i][j] == row[i] && matrix[i][j] == col[j] {
				ans = append(ans, row[i])
			}
		}
	}
	return ans
}
