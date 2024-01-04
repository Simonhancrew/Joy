#include <vector>

using namespace std;

class Solution {
public:
  int st{};
  vector<int> mask;
  int calcu(const vector<vector<int>> &matrix) {
    const int n = matrix.size();
    const int m = matrix[0].size();
    int res = 0;
    for (int i = 0; i < n; i++) {
      if ((mask[i] & st) == mask[i])
        ++res;
    }
    return res;
  }

  int dfs(int idx, int res, vector<vector<int>> &matrix) {
    if (idx >= matrix[0].size() || res == 0) {
      int final = calcu(matrix);
      return final;
    }
    st |= (1 << idx);
    int final = dfs(idx + 1, res - 1, matrix);
    st &= ~(1 << idx);
    final = max(final, dfs(idx + 1, res, matrix));
    return final;
  }

  int maximumRows(vector<vector<int>> &matrix, int numSelect) {
    int n = matrix.size(), m = matrix[0].size();
    mask.resize(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        mask[i] |= (matrix[i][j] << j);
      }
    }
    return dfs(0, numSelect, matrix);
  }
};
