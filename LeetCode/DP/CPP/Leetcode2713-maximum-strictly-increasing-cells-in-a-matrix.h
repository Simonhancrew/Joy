#include <map>
#include <vector>

using namespace std;

// f[i][j]， 表示以(i, j)为终点的最长严格递增路径的长度
// 从小到大开始遍历，遍历到(i, j)的时候，如果在<=i,
// <=j的部分去找最大值的话，时间复杂度大了 所以需要维护一个row +
// col的max(数据结构优化dp)，然后在这个数据结构上去找最大值

class Solution {
public:
  using PII = pair<int, int>;
  int maxIncreasingCells(vector<vector<int>> &mat) {
    map<int, vector<PII>> mp;
    int n = mat.size(), m = mat[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        mp[mat[i][j]].emplace_back(i, j);
      }
    }
    vector<int> row_max(n);
    vector<int> col_max(m);
    for (const auto &[_, pos] : mp) {
      vector<int> mx;
      mx.reserve(pos.size());
      for (const auto &[x, y] : pos) {
        mx.push_back(max(row_max[x], col_max[y]) + 1);
      }
      for (int i = 0; i < pos.size(); i++) {
        auto &[x, y] = pos[i];
        row_max[x] = max(row_max[x], mx[i]);
        col_max[y] = max(col_max[y], mx[i]);
      }
    }
    return ranges::max(row_max);
  }
};
