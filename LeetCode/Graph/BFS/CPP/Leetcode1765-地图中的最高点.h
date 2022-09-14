#include <queue>
#include <vector>

using namespace std;

/*
    多源BFS
*/

class Solution {
 public:
  typedef pair<int, int> PII;
  typedef pair<PII, int> PIII;
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    queue<PIII> q;
    int n = isWater.size(), m = isWater[0].size();
    vector<vector<bool>> st(n, vector<bool>(m, false));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (isWater[i][j] == 1) q.push({{i, j}, 0}), ans[i][j] = 0;
      }
    }
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    while (q.size()) {
      auto t = q.front();
      q.pop();
      int x = t.first.first, y = t.first.second, hi = t.second;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (st[nx][ny] || isWater[nx][ny] == 1) continue;
        st[nx][ny] = true;
        ans[nx][ny] = hi + 1;
        q.push({{nx, ny}, hi + 1});
      }
    }
    return ans;
  }
};