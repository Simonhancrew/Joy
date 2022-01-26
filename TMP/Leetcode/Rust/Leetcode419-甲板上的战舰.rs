impl Solution {
    pub fn count_battleships(board: Vec<Vec<char>>) -> i32 {
        let (mut ans,n,m) = (0,board.len(),board[0].len());
        for i in 0..n {
            for j in 0..m {
                if i > 0 && board[i - 1][j] == 'X' {
                    continue;
                }
                if j > 0 && board[i][j - 1] == 'X' {
                    continue;
                }
                if board[i][j] == 'X' {
                    ans += 1;
                }
            }
        }
        ans
    }
}