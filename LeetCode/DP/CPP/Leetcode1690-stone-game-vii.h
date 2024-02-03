#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// [l, r]，A取完之后剩下[l + 1, r]或者[l, r - 1]，B要最大化价值，同样做类似的操作
// 然后循环，变成了子问题
// dfs(l, r), 获得最大A-B diff的结果，dfs(l, r) = max(选左 - dfs(l + 1, r), 选右 - dfs(l, r - 1))
// 快速求区间值可以用前缀和

class Solution {
public:
  static constexpr int N = 1e3 + 10;
  int s[N];
  int f[N][N];

  int dfs(int l, int r) {
    if (l == r) {
      return 0;
    }
    auto &res = f[l][r];
    if (res != -1) {
      return res;
    }
    res = max(s[r + 1] - s[l + 1] - dfs(l + 1, r), s[r] - s[l] - dfs(l, r - 1));
    return res;
  }

  int stoneGameVII(vector<int> &stones) {
    int n = stones.size();
    partial_sum(stones.begin(), stones.end(), s + 1);
    memset(f, -1, sizeof f);
    return dfs(0, n - 1);
  }
};
