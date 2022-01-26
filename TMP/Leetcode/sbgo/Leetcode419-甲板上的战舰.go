package sbgo

func countBattleships(board [][]byte) int {
	ans, n, m := 0, len(board), len(board[0])
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if i > 0 && board[i-1][j] == 'X' {
				continue
			}
			if j > 0 && board[i][j-1] == 'X' {
				continue
			}
			if board[i][j] == 'X' {
				ans++
			}
		}
	}
	return ans
}
