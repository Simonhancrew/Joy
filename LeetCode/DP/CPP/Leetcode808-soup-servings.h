// f[i][j]代表还剩下A的数量是i，b的数量是j的时候的概率
// 因为方案中汤的值都是25的倍数，所以可以缩小一点
// 又因为对于A分汤的期望是大于B的期望很多的因此，在大于一定数值的时候
// 既可以认为A永远先结束
class Solution {
 public:
  double soupServings(int n) {
    n = (n + 24) / 25;
    if (n >= 200) return 1;
    vector<vector<double>> f(n + 1, vector<double>(n + 1));
    auto gen = [](int x) { return max(0, x); };
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        if (!i && !j)
          f[i][j] = 0.5;
        else if (i && !j)
          f[i][j] = 0;
        else if (!i && j)
          f[i][j] = 1;
        else {
          f[i][j] =
              (f[gen(i - 4)][j] + f[gen(i - 3)][gen(j - 1)] + f[gen(i - 2)][gen(j - 2)] + f[gen(i - 1)][gen(j - 3)]) /
              4;
        }
      }
    }
    return f[n][n];
  }
};