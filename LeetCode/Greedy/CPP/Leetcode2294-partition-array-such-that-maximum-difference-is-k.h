class Solution {
 public:
  int partitionArray(vector<int> &nums, int k) {
    int n = nums.size();
    ranges::sort(nums);
    int cnt = 1, pre = nums[0];
    for (int i = 0; i < n; ++i) {
      if (nums[i] - pre > k) {
        cnt++;
        pre = nums[i];
      }
    }
    return cnt;
  }
};
