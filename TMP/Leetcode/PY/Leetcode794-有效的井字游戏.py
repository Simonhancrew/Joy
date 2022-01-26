class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        cntx,cnto = 0,0
        for i in range(3):
            for j in range(3):
                if board[i][j] == 'O': cnto += 1
                elif board[i][j] == 'X': cntx += 1
        if cnto != cntx and cnto != cntx - 1: return False
        def check(t):
            for i in range(3):
                if board[0][i] == board[1][i] == board[2][i] == t:
                    return True
                if board[i][0] == board[i][1] == board[i][2] == t:
                    return True
            if board[0][0] == board[1][1] == board[2][2] == t:
                return True
            if board[0][2] == board[1][1] == board[2][0] == t:
                return True
            return False 
        if check('O') and cnto != cntx: return False
        if check('X') and cntx != cnto + 1: return False
        return True 