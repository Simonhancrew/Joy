#include <vector>

using namespace std;

// 贡献法，求左边第一个比他小的，求右边第一个比他大的
// 为了不重不漏(当数组中有重复的值时，会重复计算)，要求左边的都严格小于
// 右边的都大于等于

class Solution {
 public:
  static constexpr int MOD = 1e9 + 7;
  using LL = long long;
  int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> l(n, -1);
    vector<int> q;
    for (int i = 0; i < n; i++) {
      while (!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
      if (q.empty())
        l[i] = i + 1;
      else
        l[i] = i - q.back();
      q.push_back(i);
    }
    LL ans = 0;
    q.clear();
    // vector<int> r(n);
    for (int i = n - 1; i >= 0; i--) {
      while (!q.empty() && arr[q.back()] >= arr[i]) q.pop_back();
      if (q.empty())
        ans = (ans + (LL)arr[i] * l[i] * (n - i)) % MOD /*, r[i] = (n - i)*/;
      else
        ans = (ans + (LL)l[i] * (q.back() - i) * arr[i]) %
              MOD /*, r[i] = (q.back() - i)*/;
      q.push_back(i);
    }
    // for (int i = 0;i < n;i++) cout << l[i] << ' ';
    // cout << '\n';
    // for (int i = 0;i < n;i++) cout << r[i] << ' ';
    // cout << '\n';
    return ans;
  }
};