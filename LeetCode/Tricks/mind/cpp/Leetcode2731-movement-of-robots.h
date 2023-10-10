#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 撞完之后看作换编号，这样就不用处理碰撞行为
// 最后算全部的距离，用贡献法
// 对终点排序，dis[i, i + 1]会贡献多少次，只要跨越[i, i + 1]就贡献
// i左可能有i个点，右边可能有n - i个点，一共就是i * (n - i)

class Solution {
 public:
  static const int MOD = 1e9 + 7;
  using LL = long long;
  int sumDistance(vector<int>& nums, string s, int d) {
    vector<LL> aft;
    int n = nums.size();
    aft.resize(n);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R')
        aft[i] = (nums[i] + d);
      else
        aft[i] = (nums[i] - d);
    }
    sort(aft.begin(), aft.end());
    LL ans = 0;
    for (int i = 1; i < n; i++) {
      LL dis = aft[i] - aft[i - 1];
      ans = (ans + (dis * i % MOD) * (n - i) % MOD) % MOD;
    }
    return ans;
  }
};
