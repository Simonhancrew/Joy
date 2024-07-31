#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  using LL = long long;
  int minRectanglesToCoverPoints(vector<vector<int>> &points, int w) {
    ranges::sort(points, [](auto &l, auto &r) { return l[0] < r[0]; });
    LL limit = -1;
    int cnt = 0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
      auto x = points[i][0];
      if (x > limit) {
        cnt++;
        limit = (LL)x + w;
      }
    }
    return cnt;
  }
};
