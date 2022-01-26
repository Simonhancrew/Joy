/**
 * @param {string[]} board
 * @return {boolean}
 */
 var validTicTacToe = function(board) {
    let cntx = 0,cnto = 0;
    for(let i = 0;i < 3;i++){
        for(let j = 0;j < 3;j++) {
            if(board[i][j] == 'X') cntx++;
            else if(board[i][j] == 'O') cnto++;
        }
    }
    let check = function(t){
        for(let i = 0;i < 3;i++){
            for(let j = 0;j < 3;j++) {
                if(board[0][i] == t && board[1][i] == t && board[2][i] == t) return true;
                if(board[i][0] == t && board[i][1] == t && board[i][2] == t) return true;
            }
        }
        if(board[0][0] == t && board[1][1] == t && board[2][2] == t) return true;
        if(board[0][2] == t && board[1][1] == t && board[2][0] == t) return true;
        return false;
    }
    if(cntx != cnto && cnto != cntx - 1) return false;
    if(check('O') && cntx != cnto) return false;
    // console.log(check('O'));
    if(check('X') && cnto != cntx - 1) return false;
    return true;
};