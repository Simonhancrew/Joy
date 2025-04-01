class Solution {
 public:
  using LL = long long;
  long long mostPoints(vector<vector<int>> &questions) {
    int n = questions.size();
    vector<LL> f(n, -1);
    auto dfs = [&](this auto &&dfs, int i) -> LL {
      if (i >= n) {
        return 0;
      }
      auto &res = f[i];
      if (res != -1) {
        return res;
      }
      res = 0;
      res = max(questions[i][0] + dfs(i + questions[i][1] + 1), dfs(i + 1));
      return res;
    };
    return dfs(0);
  }
};
