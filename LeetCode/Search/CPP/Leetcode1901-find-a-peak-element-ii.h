#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int l = -1, r = n - 1;
    auto find_max = [](const vector<int>& arr) -> int {
      return max_element(arr.cbegin(), arr.cend()) - arr.cbegin();
    };
    while (l + 1 < r) {
      int mid = l + r >> 1;
      int j = find_max(mat[mid]);
      if (mat[mid][j] > mat[mid + 1][j])
        r = mid;
      else
        l = mid;
    }
    return {l + 1, find_max(mat[l + 1])};
  }
};
