package sbgo

func isValidSudoku(board [][]byte) bool {
	var row, col [9][10]int
	var box [3][3][10]int
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if board[i][j] == '.' {
				continue
			}
			u := board[i][j] - '0'
			row[i][u]++
			col[j][u]++
			box[i/3][j/3][u]++
			if row[i][u] > 1 || col[j][u] > 1 || box[i/3][j/3][u] > 1 {
				return false
			}
		}
	}
	return true
}
