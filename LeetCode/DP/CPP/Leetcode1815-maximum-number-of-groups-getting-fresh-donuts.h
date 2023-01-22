// 整除的直接去掉， 不能整除的配对去掉
// 剩下的就是需要做考虑的情况，直接记忆化
// 其实也可以用模拟退火->重排序列找到最优解就是典型的模拟退火
class Solution {
 public:
  int n = 0;
  vector<int> cnt;
  map<vector<int>, int> mp;
  int dfs(int pre) {
    if (mp.count(cnt)) return mp[cnt];
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (cnt[i]) {
        cnt[i]--;
        ans = max(ans, (pre == 0) + dfs((pre + i) % n));
        cnt[i]++;
      }
    }
    return mp[cnt] = ans;
  }
  int maxHappyGroups(int batchSize, vector<int>& groups) {
    n = batchSize;
    cnt.resize(n);
    int base = 0;
    for (const auto& x : groups) {
      if (x % batchSize == 0)
        ++base;
      else if (cnt[n - (x % n)] > 0) {
        cnt[n - (x % n)]--;
        base++;
      } else {
        cnt[x % batchSize]++;
      }
    }
    return base + dfs(0);
  }
};