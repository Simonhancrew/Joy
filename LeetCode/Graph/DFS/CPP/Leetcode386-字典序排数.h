class Solution {
 public:
  vector<int> res;
  vector<int> lexicalOrder(int n) {
    for (int i = 1; i <= 9; i++) dfs(i, n);
    return res;
  }
  void dfs(int cur, int n) {
    if (cur <= n)
      res.push_back(cur);
    else
      return;
    for (int i = 0; i <= 9; i++) dfs(cur * 10 + i, n);
  }
};