#include <vector>

using namespace std;


#if 0
class Solution {
 public:
  bool canSplitArray(vector<int>& nums, int m) {
    int n = nums.size();
    if (n <= 2) return true;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + nums[i - 1];
    if (p[n] < m) return false;
    vector<vector<int>> f(n, vector<int>(n, false));
    auto judge = [&](int l, int mid, int j) {
      int ll = mid - l, rl = j - mid + 1;
      int ls = p[mid] - p[l], rs = p[j + 1] - p[mid];
      return ((ls >= m || ll == 1) && (rs >= m || rl == 1) && f[l][mid - 1] &&
              f[mid][j]);
    };
    for (int len = 1; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        if (len <= 2)
          f[i][j] = true;
        else {
          for (int k = i + 1; k <= j; k++) {
            f[i][j] |= judge(i, k, j);
          }
        }
      }
    }
    return f[0][n - 1];
  }
};
#endif

// 只要有两相邻数之和大于2就可以剥洋葱那样分割
class Solution {
 public:
  bool canSplitArray(vector<int>& nums, int m) {
    int n = nums.size();
    if (n <= 2) return true;
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] + nums[i] >= m) return true;
    }
    return false;
  }
};
