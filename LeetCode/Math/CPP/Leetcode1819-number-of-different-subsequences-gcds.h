// 暴力枚举，记录最大的值
// 然后枚举[1, mx], 如果枚举值的倍数的最大公约数都是i的话
// 其子序列的最大公约数也是i拿到这个i值就可以了
class Solution {
 public:
  int countDifferentSubsequenceGCDs(vector<int>& nums) {
    const int N = 2e5 + 10;
    vector<int> mp(N, 0);
    int mx = 0;
    for (auto x : nums) {
      mp[x] = true;
      mx = max(mx, x);
    }
    int ans = 0;
    for (int i = 1; i <= mx; i++) {
      int g = 0;
      for (int j = i; j <= mx && g != i; j += i) {
        if (mp[j]) g = gcd(g, j);
      }
      if (g == i) ans++;
    }
    return ans;
  }
};