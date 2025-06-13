class Solution {
 public:
  int minimizeMax(vector<int> &nums, int p) {
    sort(nums.begin(), nums.end());
    int l = -1, r = nums.back() - nums[0] + 1;
    auto check = [&](int diff) {
      int cnt = 0;
      for (int i = 0; i + 1 < nums.size(); ++i) {
        if (nums[i + 1] - nums[i] <= diff) {
          cnt++;
          i++;
        }
      }
      return cnt >= p;
    };
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return r;
  }
};
