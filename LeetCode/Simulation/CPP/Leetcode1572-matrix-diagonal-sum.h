#include <vector>

using namespace std;

class Solution {
 public:
  int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int l = 0, r = n - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += mat[i][l];
      if (l != r) {
        ans += mat[i][r];
      }
      l++, r--;
    }
    return ans;
  }
};
