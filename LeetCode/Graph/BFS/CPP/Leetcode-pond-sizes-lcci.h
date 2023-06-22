#include <queue>

using namespace std;

class Solution {
 public:
  using PII = pair<int, int>;
  vector<int> pondSizes(vector<vector<int>>& land) {
    vector<int> res;
    int n = land.size(), m = land[0].size();
    vector<vector<int>> st(n, vector<int>(m));
    auto bfs = [&](int x, int y) {
      queue<PII> q;
      int ans = 0;
      q.emplace(x, y);
      st[x][y] = true;
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        ++ans;
        for (int i = -1; i < 2; i++) {
          for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) continue;
            int nx = x + i, ny = y + j;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (st[nx][ny] || land[nx][ny] != 0) continue;
            st[nx][ny] = 1;
            q.emplace(nx, ny);
          }
        }
      }
      return ans;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (land[i][j] == 0 && !st[i][j]) {
          int cur = bfs(i, j);
          res.push_back(cur);
        }
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
};