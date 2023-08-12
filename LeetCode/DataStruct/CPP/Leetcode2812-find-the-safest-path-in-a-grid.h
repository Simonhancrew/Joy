#include <numeric>
#include <vector>

using namespace std;  // NOLINT

class Solution {
 public:
  using PII = pair<int, int>;
  static constexpr int dx[4] = {0, 1, 0, -1};
  static constexpr int dy[4] = {1, 0, -1, 0};
  vector<int> fa;
  int find(int x) {
    if (fa[x] != x) {
      fa[x] = find(fa[x]);
    }
    return fa[x];
  }

  void merge(int x, int y) {
    if (find(x) == find(y)) return;
    fa[find(x)] = find(y);
  }
  
  int maximumSafenessFactor(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dis(n, vector<int>(n, -1));
    vector<PII> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          q.emplace_back(i, j);
          dis[i][j] = 0;
        }
      }
    }
    vector<vector<PII>> gr{q};
    while (q.size()) {
      vector<PII> ne;
      for (const auto& [x, y] : q) {
        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i], ny = y + dy[i];
          if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
          if (dis[nx][ny] >= 0) continue;
          dis[nx][ny] = gr.size();
          ne.emplace_back(nx, ny);
        }
      }
      if (ne.empty()) {
        break;
      }
      gr.push_back(ne);
      q = std::move(ne);
    }
    auto get = [n](int x, int y) { return x * n + y; };
    fa.resize(n * n);
    iota(fa.begin(), fa.end(), 0);
    for (int id = gr.size() - 1; id >= 0; id--) {
      const auto& cur = gr[id];
      for (const auto [x, y] : cur) {
        for (int i = 0;i < 4;i++) {
          int nx = x + dx[i], ny = y + dy[i];
          if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
          if (dis[nx][ny] < dis[x][y]) continue;
          merge(get(x, y), get(nx, ny));
        }
      }
      if (find(get(0, 0)) == find(get(n - 1, n - 1))) {
        return id;
      }
    }
    // abort();
    return 0;
  }
};
