#include <queue>

using namespace std;

class Solution {
 public:
  using PII = pair<int, int>;
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int ans = INT_MIN, n = points.size();
    deque<PII> q;
    for (int r = 0; r < n; r++) {
      auto& cur = points[r];
      while (q.size() && cur[0] - q.front().first > k) q.pop_front();
      if (q.size()) {
        int tar = cur[0] + cur[1];
        ans = max(ans, tar + q.front().second);
      }
      int diff = cur[1] - cur[0];
      while (q.size() && q.back().second <= diff) q.pop_back();
      q.emplace_back(cur[0], diff);
    }
    return ans;
  }
};
