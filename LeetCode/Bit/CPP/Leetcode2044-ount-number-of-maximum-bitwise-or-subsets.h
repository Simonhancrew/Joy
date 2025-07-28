class Solution {
 public:
  int countMaxOrSubsets(vector<int> &nums) {
    int n   = nums.size();
    int tar = 0, cnt = 1;
    for (int i = 1; i < (1 << n); ++i) {
      int cur = 0;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          cur |= nums[j];
        }
      }
      // cout << i << ' ' << cur << '\n';
      if (cur > tar) {
        tar = cur;
        cnt = 1;
      } else if (cur == tar) {
        cnt++;
      }
    }
    return cnt;
  }
};
