// 最大值只可能在最高塔点之下，距离越远信号越小。
class Solution {
 public:
  vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    int mx = -1, my = -1;
    for (auto t : towers) {
      mx = max(mx, t[0]);
      my = max(my, t[1]);
    }
    int tx = 0, ty = 0, qua = 0;
    auto qmi = [](int a, int b) {
      int res = 1;
      while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
      }
      return res;
    };
    for (int i = 0; i <= mx; i++) {
      for (int j = 0; j <= my; j++) {
        int q = 0;
        for (auto t : towers) {
          auto d = qmi(i - t[0], 2) + qmi(j - t[1], 2);
          if (d <= qmi(radius, 2)) {
            q += int(t[2] / (1 + sqrt(d)));
          }
        }
        if (q > qua) {
          tx = i, ty = j, qua = q;
        }
      }
    }
    return {tx, ty};
  }
};

