#if 0
// 过不掉，maxpts的iter太大，dfs转循环优化
class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    vector<double> f(n + 1, -1);
    auto dfs = [&](this auto &&dfs, int i) -> double {
      if (i > n) {
        return 0.0;
      }
      auto &res = f[i];
      if (res != -1) {
        return res;
      }
      if (i >= k) {
        res = 1;
        return res;
      }
      double tot = 0;
      for (int acc = 1; acc <= maxPts; acc++) {
        tot += dfs(i + acc);
      }
      res = tot / maxPts;
      return res;
    };
    return dfs(0);
  }
};
#endif

class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    vector<double> f(n + 1, 0);
    double s = 0;
    for (int i = n; i >= 1; i--) {
      f[i] = i >= k ? 1 : s / maxPts;
      s += f[i];
      if (i + maxPts <= n) {
        s -= f[i + maxPts];
      }
    }
    return f[0];
  }
};
