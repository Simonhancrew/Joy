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
