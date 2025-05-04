class Solution {
 public:
  int maxSum(vector<int> &nums) {
    vector<int> cnt(10, -1);
    int ans  = -1;
    auto get = [](int x) {
      int tar = 0;
      while (x) {
        tar = max(tar, x % 10);
        x /= 10;
      }
      return tar;
    };
    for (const auto x : nums) {
      auto tar = get(x);
      if (cnt[tar] > 0) {
        ans = max(ans, cnt[tar] + x);
      }
      if (cnt[tar] < x) {
        cnt[tar] = x;
      }
    }
    return ans;
  }
};
