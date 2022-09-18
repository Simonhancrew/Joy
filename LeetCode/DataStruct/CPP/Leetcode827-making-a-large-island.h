#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 首先flood fill，找到每个岛屿，然后针对每个岛屿给一个idx，算出size
// 然后遍历所有的0点，找四周的岛屿，看能不能连接起来
// 最后综合算到最大的面积

#ifdef DFS
class Solution {
 public:
  void dfs(int x, int y, vector<vector<int>> &grid, int &sz, int idx) {
    if (grid[x][y] == 0)
      return;
    vis[x][y] = idx;
    sz++;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] != -1)
        continue;
      dfs(nx, ny, grid, sz, idx);
    }
  }

  int largestIsland(vector<vector<int>> &grid) {
    n = grid.size(), m = grid[0].size();
    vis     = vector(n, vector<int>(m, -1));
    sz      = vector<int>(n * m, 0);
    int ans = 1, idx = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] && vis[i][j] == -1) {
          dfs(i, j, grid, sz[idx], idx);
          ans = max(ans, sz[idx]);
          ++idx;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!grid[i][j]) {
          unordered_set<int> neis;
          for (int d = 0; d < 4; d++) {
            int nx = i + dx[d], ny = j + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
              continue;
            if (vis[nx][ny] != -1)
              neis.insert(vis[nx][ny]);
          }
          int cur = 1;
          for (auto nei : neis) {
            cur += sz[nei];
          }
          ans = max(ans, cur);
        }
      }
    }
    return ans;
  }

 private:
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  int n = 0, m = 0;
  vector<int> sz;
  vector<vector<int>> vis;
};
#endif

// 维护集合 + size天然就是并查集的强项，同理也可以用并查集做

class Solution {
 public:
  int largestIsland(vector<vector<int>> &grid) {
    n = grid.size(), m = grid[0].size();
    p.resize(n * m, 0);
    sz.resize(n * m, 1);
    for (int i = 0; i < n * m; i++)
      p[i] = i;
    int res = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          int a = get(i, j);
          for (int d = 0; d < 4; d++) {
            int nx = i + dx[d], ny = j + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
              continue;
            if (grid[nx][ny] == 0)
              continue;
            int b = get(nx, ny);
            if (find(a) != find(b)) {
              sz[find(a)] += sz[find(b)];
              p[find(b)] = find(a);
            }
          }
          res = max(res, sz[find(a)]);
        }
      }
    }
    // cout << res << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!grid[i][j]) {
          unordered_set<int> st;
          for (int d = 0; d < 4; d++) {
            int nx = i + dx[d], ny = j + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
              continue;
            if (grid[nx][ny] == 0)
              continue;
            st.insert(find(get(nx, ny)));
          }
          int cur = 1;
          for (auto nei : st) {
            cur += sz[nei];
          }
          res = max(res, cur);
        }
      }
    }
    return res;
  }

 private:
  int get(int x, int y) {
    return x * m + y;
  }

  int find(int x) {
    if (p[x] != x)
      p[x] = find(p[x]);
    return p[x];
  }
  int n, m;
  vector<int> p, sz;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
};