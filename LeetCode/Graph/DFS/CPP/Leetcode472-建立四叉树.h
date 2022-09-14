/*
    判断一个区域中是否全0或者全1使用二位前缀和
    然后递归的建树就可以
*/
class Solution {
 public:
  vector<vector<int>> presum;
  Node *construct(vector<vector<int>> &grid) {
    int n = grid.size();
    presum.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        presum[i][j] = presum[i - 1][j] + presum[i][j - 1] -
                       presum[i - 1][j - 1] + grid[i - 1][j - 1];
      }
    }
    return dfs(1, 1, n, n);
  }
  Node *dfs(int x1, int y1, int x2, int y2) {
    int n = x2 - x1 + 1;
    int sum = presum[x2][y2] - presum[x2][y1 - 1] - presum[x1 - 1][y2] +
              presum[x1 - 1][y1 - 1];
    if (sum == 0 || sum == n * n) return new Node(!!sum, true);
    auto node = new Node(0, false);
    int m = n / 2;
    node->topLeft = dfs(x1, y1, x1 + m - 1, y1 + m - 1);
    node->bottomLeft = dfs(x1 + m, y1, x2, y1 + m - 1);
    node->topRight = dfs(x1, y1 + m, x1 + m - 1, y2);
    node->bottomRight = dfs(x1 + m, y1 + m, x2, y2);
    return node;
  }
};