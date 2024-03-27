#include <vector>

using namespace std;

class Solution {
public:
  using LL = long long;
  static constexpr int MOD = 1e9 + 7;
  vector<int> f;
  int sz;
  int find(int x) {
    if (f[x] != x) {
      f[x] = find(f[x]);
      return f[x];
    }
    return f[x];
  }

  void merge(int x, int y) {
    auto fx = find(x);
    auto fy = find(y);
    if (fx == fy) {
      return;
    }
    f[fx] = fy;
    sz--;
  }

  int qpow(int x, int y = 2) {
    int res = 1;
    while (x) {
      if (x & 1) {
        res = ((LL)res * y) % MOD;
      }
      x >>= 1;
      y = ((LL)y * y) % MOD;
    }
    return res;
  }

  int countWays(vector<vector<int>> &ranges) {
    int n = ranges.size();
    f.resize(n);
    sz = n;
    iota(f.begin(), f.end(), 0);
    sort(ranges.begin(), ranges.end());
    int mx = ranges[0][1];
    for (int i = 1; i < n; i++) {
      if (ranges[i][0] <= mx) {
        merge(i, i - 1);
        mx = max(ranges[i][1], mx);
      } else {
        mx = ranges[i][1];
      }
    }
    return qpow(sz);
  }
};
