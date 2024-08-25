class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int acc = accumulate(nums.begin(), nums.end(), 0);
    if (acc % k != 0) {
      return false;
    }
    sort(nums.begin(), nums.end());
    int tar = acc / k;
    int n = nums.size();
    vector<int> st(n, 0);
    auto dfs = [&](auto &&dfs, int idx, int cnt, int cur) -> bool {
      if (cnt == k) {
        return true;
      }
      if (idx < 0) {
        return false;
      }
      bool res = 0;
      for (int i = idx; i >= 0; i--) {
        if (st[i] || cur + nums[i] > tar)
          continue;
        st[i] = true;
        if (cur + nums[i] < tar)
          res |= dfs(dfs, idx - 1, cnt, cur + nums[i]);
        else
          res |= dfs(dfs, n - 1, cnt + 1, 0);
        st[i] = false;
        if (res) {
          return true;
        }
        // 可行性剪枝，最大的选了还没答案，后面的更不可能了
        if (cur == 0)
          return false;
      }
      return false;
    };
    auto res = dfs(dfs, n - 1, 0, 0);
    return res;
  }
};
