package sbgo

func validTicTacToe(board []string) bool {
	cntx, cnto := 0, 0
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if board[i][j] == 'X' {
				cntx++
			}
			if board[i][j] == 'O' {
				cnto++
			}
		}
	}
	check := func(t byte) bool {
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				if board[i][0] == t && board[i][1] == t && board[i][2] == t {
					return true
				}
				if board[0][i] == t && board[1][i] == t && board[2][i] == t {
					return true
				}
			}
		}
		if board[0][0] == t && board[1][1] == t && board[2][2] == t {
			return true
		}
		if board[0][2] == t && board[1][1] == t && board[2][0] == t {
			return true
		}

		return false
	}
	if cnto != cntx && cnto != cntx-1 {
		return false
	}
	if check('X') && cnto != cntx-1 {
		return false
	}
	if check('O') && cnto != cntx {
		return false
	}
	return true
}
