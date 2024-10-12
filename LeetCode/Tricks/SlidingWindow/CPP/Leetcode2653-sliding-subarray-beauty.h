/*
  开始想维护好vector然后二分插入，但是这个数值范围足够小，计数排序暴力找第x小就可以了
*/
class Solution {
public:
  vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
    int n = nums.size();
    static constexpr int diff = 50;
    vector<int> ans(n - k + 1);
    vector<int> tmp(diff * 2 + 1);
    int plc = 0;
    for (int i = 0; i < n; i++) {
      ++tmp[nums[i] + diff];
      if (i < k - 1)
        continue;
      int left = x;
      for (int j = 0; j < diff; j++) {
        left -= tmp[j];
        if (left <= 0) {
          ans[plc] = j - diff;
          break;
        }
      }
      plc++;
      --tmp[nums[i - k + 1] + diff];
    }
    return ans;
  }
};
