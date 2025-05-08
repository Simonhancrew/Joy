class Solution {
 public:
  static constexpr int dx[4] = {0, 1, 0, -1};
  static constexpr int dy[4] = {1, 0, -1, 0};
  using PII                  = tuple<int, int, int>;
  int minTimeToReach(vector<vector<int>> &moveTime) {
    int n = moveTime.size(), m = moveTime[0].size();
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.emplace(0, 0, 1);
    while (!heap.empty()) {
      auto [d, t, add] = heap.top();
      heap.pop();
      auto x = t / m, y = t % m;
      if (x == n - 1 && y == m - 1) {
        return d;
      }
      if (moveTime[x][y] < 0) {
        continue;
      }
      moveTime[x][y] = -1;
      for (int i = 0; i < 4; i++) {
        auto nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || moveTime[nx][ny] < 0) {
          continue;
        }
        auto nd = moveTime[nx][ny];
        if (d >= nd) {
          nd = d + add;
        } else {
          nd += add;
        }
        heap.emplace(nd, nx * m + ny, add ^ 3);
      }
    }
    return -1;
  }
};
