#include <algorithm>
#include <numeric>
#include <vector>

using std::min;
using std::vector;

class Solution {
 public:
  int minSwap(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    vector<vector<int>> f(n, vector<int>(2, INT_MAX));
    f[0][0] = 0, f[0][1] = 1;
    for (int i = 1; i < n; i++) {
      if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
        f[i][0] = min(f[i][0], f[i - 1][0]);
        f[i][1] = min(f[i][1], f[i - 1][1] + 1);
      }

      if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
        f[i][0] = min(f[i][0], f[i - 1][1]);
        f[i][1] = min(f[i][1], f[i - 1][0] + 1);
      }
    }
    return min(f[n - 1][0], f[n - 1][1]);
  }
};