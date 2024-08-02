#include <vector>
#include <numeric>

using namespace std;

// 枚举中心，统计行列上的1总数

class Solution {
public:
  using LL = long long;
  long long numberOfRightTriangles(vector<vector<int>> &grid) {
    LL ans = 0;
    int m = grid[0].size();
    vector<int> col(m, -1);
    for (const auto &row : grid) {
      for (int i = 0; i < m; i++) {
        col[i] += row[i];
      }
    }
    for (const auto &row : grid) {
      auto row_sum = reduce(row.begin(), row.end(), 0) - 1;
      for (int i = 0; i < m; i++) {
        if (row[i] == 1) {
          ans += row_sum * col[i];
        }
      }
    }
    return ans;
  }
};
