#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    vector<int> rec(min(n, m));
    for (int k = 2 - m; k < n - 1; k++) {
      int l_i = max(0, k);
      int r_i = min(n, k + m);
      for (int i = l_i, idx = 0; i < r_i; i++, idx++) {
        int j = i - k;
        rec[idx] = mat[i][j];
      }
      sort(rec.begin(), rec.begin() + r_i - l_i);
      for (int i = l_i, idx = 0; i < r_i; i++, idx++) {
        int j = i - k;
        mat[i][j] = rec[idx];
      }
    }
    return std::move(mat);
  }
};
