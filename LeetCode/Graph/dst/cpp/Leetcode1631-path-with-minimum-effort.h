#include <queue>
#include <tuple>

using namespace std;

class Solution {
 public:
  static constexpr int dx[4] = {0, 1, 0, -1};
  static constexpr int dy[4] = {1, 0, -1, 0};
  using PII = pair<int, int>;
  int minimumEffortPath(vector<vector<int>>& heights) {
    auto n = heights.size();
    auto m = heights[0].size();
    auto calc = [m](int x, int y) { return x * m + y; };
    auto get = [m](int x) { return make_pair<int, int>(x / m, x % m); };
    vector<int> dis(n * m, INT_MAX);
    dis[0] = 0;
    priority_queue<PII, vector<PII>, greater<>> heap;
    vector<int> st(n * m);
    heap.emplace(0, 0);
    while (!heap.empty()) {
      auto t = heap.top();
      heap.pop();
      auto& [d, idx] = t;
      auto [x, y] = get(idx);
      if (x == n - 1 && y == m - 1) break;
      if (st[idx] != 0) continue;
      st[idx] = 1;
      for (int i = 0; i < 4; i++) {
        auto nx = x + dx[i];
        auto ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        auto ne = calc(nx, ny);
        auto cur = max(d, abs(int(heights[x][y]) - int(heights[nx][ny])));
        if (dis[ne] > cur) {
          dis[ne] = cur;
          heap.emplace(dis[ne], ne);
        }
      }
    }
    return dis[n * m - 1];
  }
};
