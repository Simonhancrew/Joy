class Solution {
 public:
  static constexpr int MOD = 1e9 + 7;
  using LL                 = long long;
  vector<int> productQueries(int n, vector<vector<int>> &queries) {
    auto get = [](int n) {
      vector<int> res;
      while (n) {
        int cur = (n & -n);
        res.push_back(cur);
        n ^= cur;
      }
      return res;
    };
    vector<int> powers = get(n);
    int m              = powers.size();
    vector<vector<int>> pre_acc(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
      pre_acc[i][i] = powers[i];
      for (int j = i + 1; j < m; j++) {
        pre_acc[i][j] = (LL)pre_acc[i][j - 1] * powers[j] % MOD;
      }
    }
    vector<int> res;
    for (const auto &q : queries) {
      res.push_back(pre_acc[q[0]][q[1]]);
    }
    return res;
  }
};
