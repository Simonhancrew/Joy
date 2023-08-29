#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// 排序之后做dp 不重不漏

class Solution {
 public:
  static constexpr int MOD = 1e9 + 7;
  using LL = long long;
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int> f(n, 0);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[arr[i]] = i;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      f[i] = 1;
      for (int j = 0; j < i; j++) {
        if (arr[i] % arr[j] == 0) {
          int ot = arr[i] / arr[j];
          if (mp.count(ot)) {
            int k = mp[ot];
            f[i] = (f[i] + ((LL)f[j] * f[k])) % MOD;
          }
        }
      }
      res = (res + f[i]) % MOD;
    }
    return res % MOD;
  }
};
