// 如果都不同的话找到最小的，然后做个映射排序
// 随后按照顺序填ans就可以了，填的时候记录一个行列最大值
// 填入的最大值是mx + 1, 这个mx是同行列的最大值， 并且更新当前行列最大值
// 有重复的话，合并相同的部分，同样排个序，然后合并的部分集体赋值
// 这里的秩是当前重复值集合{(x, y)}中max({row[x], col[y]}) + 1,需要遍历一下
class Solution {
 public:
  using LL = long long;
  vector<int> f;
  vector<int> sz;
  int n{}, m{};
  int find(int x) {
    if (x != f[x]) {
      f[x] = find(f[x]);
    }
    return f[x];
  }
  // 按秩合并，几乎没暖优化
  void merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (sz[px] > sz[py]) {
      f[py] = px;
      sz[px] += sz[py];
    } else {
      f[px] = py;
      sz[py] += sz[px];
    }
  }

  int get(int x, int y) { return x * m + y; }

  void build(const vector<vector<int>>& matrix) {
    // row
    for (int i = 0; i < n; i++) {
      unordered_map<int, vector<int>> mp;
      for (int j = 0; j < m; j++) {
        mp[matrix[i][j]].push_back(get(i, j));
      }
      for (const auto& [k, v] : mp) {
        for (int idx = 1; idx < v.size(); idx++) {
          merge(v[idx - 1], v[idx]);
        }
      }
    }
    // col
    for (int i = 0; i < m; i++) {
      unordered_map<int, vector<int>> mp;
      for (int j = 0; j < n; j++) {
        mp[matrix[j][i]].push_back(get(j, i));
      }
      for (const auto& [k, v] : mp) {
        for (int idx = 1; idx < v.size(); idx++) {
          merge(v[idx - 1], v[idx]);
        }
      }
    }
  }

  vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
    n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<int> order(n * m);
    f.resize(n * m), sz.resize(m * n, 1);
    for (int i = 0; i < m * n; i++) {
      f[i] = i;
      order[i] = i;
    }
    build(matrix);
    sort(order.begin(), order.end(), [this, &matrix](int l, int r) {
      int pl = find(l), pr = find(r);
      int vl = matrix[l / m][l % m], vr = matrix[r / m][r % m];
      if (vl != vr) return vl < vr;
      return pl < pr;
    });
    vector<int> row(n), col(m);
    for (int i = 0; i < m * n;) {
      int cur = find(order[i]);
      int j = i;
      int mx = 0;
      while (j < n * m && find(order[j]) == cur) {
        int x = order[j] / m, y = order[j] % m;
        mx = max(mx, row[x]);
        mx = max(mx, col[y]);
        j++;
      }
      while (i < j) {
        int x = order[i] / m, y = order[i] % m;
        ans[x][y] = mx + 1;
        row[x] = max(row[x], mx + 1);
        col[y] = max(col[y], mx + 1);
        i++;
      }
    }
    return ans;
  }
};