#include <vector>

using namespace std;

// 分组问题，而且数据范围很小
// f[s]是状态s二进制枚举下的最好答案
// f[s] = min(f[s], f[t] + mx - mn), t是s的一个子枚举
// 递归求取一下枚举t的可能值

class Solution {
 public:
  int n, m, cnt;
  static const int INF = 1e9;
  int rec[16], f[1 << 16];
  vector<int> nums;
  void solve(int seen, int acc, int cur, int idx, int mx, int mn,
             const int tar) {
    if (acc == m) {
      f[tar] = min(f[tar], f[tar ^ cur] + mx - mn);
      return;
    }
    if (acc + cnt - idx < m) {
      return;
    }
    if (!((seen >> nums[rec[idx]]) & 1)) {
      solve(seen | (1 << nums[rec[idx]]), acc + 1, cur | (1 << rec[idx]),
            idx + 1, max(mx, nums[rec[idx]]), min(mn, nums[rec[idx]]), tar);
    }
    solve(seen, acc, cur, idx + 1, mx, mn, tar);
  }
  int minimumIncompatibility(vector<int>& _nums, int k) {
    n = _nums.size();
    if (n % k != 0) return -1;
    nums = _nums;
    m = n / k;
    sort(nums.begin(), nums.end());
    f[0] = 0;
    for (int st = 1; st < (1 << n); st++) {
      cnt = 0;
      for (int i = 0; i < n; i++) {
        if ((st >> i) & 1) {
          rec[cnt++] = i;
        }
      }
      if (cnt % m != 0) continue;
      f[st] = INF;
      solve(0, 0, 0, 0, 0, INF, st);
    }
    if (f[(1 << n) - 1] == INF) {
      return -1;
    }
    return f[(1 << n) - 1];
  }
};