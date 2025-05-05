/*
  考虑f[i]表示长度为i的矩形的铺法数，f[i]可以由以下几种方式得到：
    1. 竖着放的1 * 2，去掉的话变成2 * (i - 1)的方案, f[i - 1]
    2. 两个横着放的2 * 1, 去掉的话变成2 * (i - 2)的方案, f[i - 2]
    3. 最右边放L型，可以对称放，中间是2 * 1的横着摆，可以放(0, 1, 2, ..., i-3)个，对应的左边的就是
      f[i - 3], ... f[0]
  递推
    f[i] = f[i - 1] + f[i - 2] + 2 * sum(0, i -3)f[j]
    f[n] - f[n - 1]得到f[n]的递推式
*/
class Solution {
 public:
  using LL                 = long long;
  static constexpr int MOD = 1e9 + 7;
  int numTilings(int n) {
    if (n == 1) {
      return 1;
    }
    vector<LL> f(n + 1);
    f[0] = f[1] = 1;
    f[2]        = 2;
    for (int i = 3; i <= n; i++) {
      f[i] = (f[i - 1] * 2 + f[i - 3]) % MOD;
    }
    return f[n];
  }
};
