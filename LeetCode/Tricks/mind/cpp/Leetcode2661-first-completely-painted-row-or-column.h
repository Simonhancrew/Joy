#include <vector>
#include <unordered_map>

using namespace std;

// 映射arr里的值到下标, 然后看看mat里每行每列的下标的最大值，
// 对这些最大值求一个整体的最小值

class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    unordered_map<int, int> mp;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      mp[arr[i]] = i;
    }
    n = mat.size();
    int m = mat[0].size();
    int row_min_idx = INT_MAX, col_min_idx = INT_MAX;
    for (int i = 0; i < n; i++) {
      int max_idx = -1;
      for (int j = 0; j < m; j++) {
        int val = mat[i][j];
        max_idx = max(max_idx, mp[val]);
      }
      row_min_idx = min(row_min_idx, max_idx);
    }
    for (int j = 0; j < m; j++) {
      int max_idx = -1;
      for (int i = 0; i < n; i++) {
        int val = mat[i][j];
        max_idx = max(max_idx, mp[val]);
      }
      col_min_idx = min(col_min_idx, max_idx);
    }
    return min(row_min_idx, col_min_idx);
  }
};
