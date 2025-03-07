class Solution {
 public:
  int beautifulSubsets(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    int n    = nums.size();
    int ans  = -1;
    auto dfs = [&](this auto &&dfs, int i) {
      if (i == n) {
        ++ans;
        return;
      }
      dfs(i + 1);
      auto cur = nums[i];
      if (!mp[cur - k] && !mp[cur + k]) {
        mp[cur]++;
        dfs(i + 1);
        mp[cur]--;
      }
    };
    dfs(0);
    return ans;
  }
};
