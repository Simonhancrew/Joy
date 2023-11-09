#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 最短路扩展
// 算一下每个点着火的最小时间然后二分答案，看看能不能走通

class Solution {
 public:
  static constexpr int dx[4] = {0, 1, 0, -1};
  static constexpr int dy[4] = {1, 0, -1, 0};
  static constexpr int INF = 1e9;
  using PII = pair<int, int>;
  int maximumMinutes(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> fire(n, vector<int>(m, INF));
    queue<PII> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          q.emplace(i, j);
          fire[i][j] = 0;
        }
      }
    }
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = t.first + dx[i], ny = t.second + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (grid[nx][ny] == 2) continue;
        if (fire[nx][ny] != INF) continue;
        fire[nx][ny] = fire[t.first][t.second] + 1;
        q.emplace(nx, ny);
      }
    }
    auto pass = [&](int begin) {
      if (begin >= fire[0][0]) {
        return false;
      }
      vector<vector<int>> dis(n, vector<int>(m, INF));
      dis[0][0] = begin;
      queue<PII> q;
      q.emplace(0, 0);
      while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
          int nx = t.first + dx[i], ny = t.second + dy[i];
          if (nx == n - 1 && ny == m - 1) {
            return dis[t.first][t.second] + 1 <= fire[n - 1][m - 1];
          }
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if (grid[nx][ny] == 2) continue;
          if (dis[t.first][t.second] + 1 >= fire[nx][ny]) continue;
          if (dis[t.first][t.second] + 1 < dis[nx][ny]) {
            dis[nx][ny] = dis[t.first][t.second] + 1;
            q.emplace(nx, ny);
          }
        }
      }
      return false;
    };

    int l = 0, r = m * n;
    while (l < r) {
      auto mid = l + r + 1 >> 1;
      if (pass(mid))
        l = mid;
      else
        r = mid - 1;
    }
    if (l == 0 && !pass(l)) {
      return -1;
    }
    if (l == m * n && pass(l)) {
      return INF;
    }
    return l;
  }
};
