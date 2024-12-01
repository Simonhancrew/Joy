class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<string> board;
    for (int i = 0; i < n; i++) {
      board.emplace_back(n, '.');
    }
    vector<int> col(n), dg(n + n), rdg(n + n);
    vector<vector<string>> res;
    auto dfs = [&](auto &&dfs, int row) {
      if (row == n) {
        res.push_back(board);
        return;
      }
      for (int i = 0; i < n; i++) {
        if (col[i] || dg[row + i] || rdg[n - row + i])
          continue;
        col[i] = dg[row + i] = rdg[n - row + i] = 1;
        board[row][i]                           = 'Q';
        dfs(dfs, row + 1);
        board[row][i] = '.';
        col[i] = dg[row + i] = rdg[n - row + i] = 0;
      }
    };
    dfs(dfs, 0);
    return res;
  }
};
