class Solution {
public:
  int maxTotalReward(vector<int> &rewardValues) {
    sort(rewardValues.begin(), rewardValues.end());
    int f[rewardValues.back() << 1];
    memset(f, -1, sizeof f);
    function<int(int)> dfs = [&](int acc) {
      if (f[acc] != -1) {
        return f[acc];
      }
      auto &ans = f[acc];
      auto it = upper_bound(rewardValues.begin(), rewardValues.end(), acc);
      ans = 0;
      while (it != rewardValues.end()) {
        auto idx = it - rewardValues.begin();
        ans = max(ans, rewardValues[idx] + dfs(acc + rewardValues[idx]));
        ++it;
      }
      return ans;
    };
    return dfs(0);
  }
};
