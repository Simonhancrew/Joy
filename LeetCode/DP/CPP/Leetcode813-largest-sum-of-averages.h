#include <vector>
#include <algorithm>

using namespace std;

// f[i][j] 表示前i个数，分成j组，最大的平均数和
// f[i][j] = max(f[i][j], f[0..x][j - 1] + (s[i] - s[x]) / (i - x)), 其中x属于(0, i)
// 开始全部是-INF, f[0][0] = 0

class Solution {
 public:
  double largestSumOfAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<double>> f(n + 1, vector<double>(k + 1, -1e9));
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        for (int q = 0; q < i; q++) {
          f[i][j] = max(f[i][j], f[q][j - 1] + (s[i] - s[q]) / (double)(i - q));
        }
      }
    }
    return f[n][k];
  }
};