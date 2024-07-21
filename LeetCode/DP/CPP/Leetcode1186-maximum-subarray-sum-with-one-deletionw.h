#include <vector>

using namespace std;

class Solution {
public:
  int maximumSum(vector<int> &arr) {
    const int n = arr.size();
    vector<int> f(n), g(n);
    f[0] = arr[0], g[0] = -1e5;
    int ans = f[0];
    for (int i = 1; i < n; i++) {
      f[i] = max(f[i - 1] + arr[i], arr[i]);
      g[i] = max({g[i - 1] + arr[i], f[i - 1]});
      ans = max({ans, g[i], f[i]});
    }
    return ans;
  }
};

#if dfs
class Solution {
public:
  int maximumSum(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> f(n, vector<int>(2, -1));
    int ans = INT_MIN;
    auto dfs = [&arr, &f, &ans](auto &&dfs, int i, int can) {
      int &res = f[i][can];
      if (res != -1) {
        return res;
      }
      if (i == 0) {
        res = arr[0];
        ans = max(ans, res);
        return res;
      }
      res = arr[i];
      auto cur = dfs(dfs, i - 1, can) + arr[i];
      if (can) {
        cur = max(cur, dfs(dfs, i - 1, 0));
      }
      res = max(res, cur);
      ans = max(ans, res);
      return res;
    };
    dfs(dfs, n - 1, 1);
    return ans;
  }
};
#endif
