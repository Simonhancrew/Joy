// 海平面连通问题
class Solution {
 public:
  int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int n = grid.size(), m = grid[0].size(), k = queries.size();
    int mn = n * m;
    vector<vector<int>> cp;
    vector<int> ref(k), p(mn), cnt(mn);
    fill(cnt.begin(), cnt.end(), 1);
    function<int(int)> find = [&](int x) {
      if (p[x] != x) p[x] = find(p[x]);
      return p[x];
    };
    auto merge = [&](int x, int y) {
      if (find(x) == find(y)) return;
      cnt[find(x)] += cnt[find(y)];
      p[find(y)] = p[find(x)];
    };
    for (int i = 0; i < mn; i++) p[i] = i;
    for (int i = 0; i < k; i++) ref[i] = i;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cp.push_back({i, j, grid[i][j]});
      }
    }
    sort(cp.begin(), cp.end(), [](vector<int>& lhs, vector<int>& rhs) { return lhs[2] < rhs[2]; });
    sort(ref.begin(), ref.end(), [&queries](int l, int r) { return queries[l] < queries[r]; });
    vector<int> res(k);
    int j = 0;
    for (int i = 0; i < k; i++) {
      int q = queries[ref[i]];
      while (j < mn && cp[j][2] < q) {
        int x = cp[j][0], y = cp[j][1];
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k], ny = y + dy[k];
          if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
          if (grid[nx][ny] >= q) continue;
          merge(x * m + y, nx * m + ny);
        }
        j++;
      }
      if (grid[0][0] < q) {
        res[ref[i]] = cnt[find(0)];
      }
    }
    return res;
  }
};