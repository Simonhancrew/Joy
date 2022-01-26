var countBattleships = function(board) {
    let ans = 0,n = board.length,m = board[0].length;
    for(let i = 0;i < n;i++) {
        for(let j = 0;j < m;j++) {
            if(i > 0 && board[i - 1][j] == 'X') continue;
            if(j > 0 && board[i][j - 1] == 'X') continue;
            if(board[i][j] == 'X') ans++;
        }
    }
    return ans;
};