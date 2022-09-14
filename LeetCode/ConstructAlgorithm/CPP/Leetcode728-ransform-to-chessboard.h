/*
  观测到两个结论：
  1. 行只会有两个不一样，列同样如此
  2. 行列变换的先后顺序变换，结果是一样的。

  1比较难观察到，可以固定行，针对列做变换。
  假设两列是相同的，变换之后毫无变化。行依然是相同的。
  两列是不同的，变换之后不同的行依然不同。
  这就说明两个纬度的变化是独立的。

  因此得到的结论就是行应该只有两种不同的，才能得到最后的变换结果。列同样如此，

  又因为行列变换的先后顺序无关，可以就变第一行和第一列到最终结果。

  最终结果只有两种可能，看看那种变换的步数更少就行
*/

class Solution {
 public:
  const int INF = 0x3f3f3f3f;

  int get(int x) {
    int res = 0;
    while (x) {
      res += x & 1;
      x >>= 1;
    }
    return res;
  }

  int calcu(int x, int y) {
    if (get(x) != get(y)) return INF;
    return (get(x ^ y)) / 2;
  }

  int movesToChessboard(vector<vector<int>>& board) {
    int n = board.size();
    set<int> row, col;
    for (int i = 0; i < n; i++) {
      int c = 0, r = 0;
      for (int j = 0; j < n; j++) {
        r = (r << 1) + board[i][j];
        c = (c << 1) + board[j][i];
      }
      row.insert(r), col.insert(c);
    }
    if (row.size() != 2 || col.size() != 2) return -1;
    int r1 = *row.begin(), r2 = *row.rbegin();
    int c1 = *col.begin(), c2 = *col.rbegin();
    if ((r1 ^ r2) != (1 << n) - 1 || (c1 ^ c2) != (1 << n) - 1) return -1;
    int s1 = 0;
    for (int i = 0; i < n; i += 2) s1 |= 1 << i;
    int s2 = ((1 << n) - 1) ^ s1;
    int r_c = min(calcu(r1, s1), calcu(r1, s2));
    int c_c = min(calcu(c1, s1), calcu(c1, s2));
    int ans = r_c + c_c;
    if (ans >= INF) return -1;
    return ans;
  }
};
