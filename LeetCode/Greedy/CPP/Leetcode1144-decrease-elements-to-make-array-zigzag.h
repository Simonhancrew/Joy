class Solution {
 public:
  int movesToMakeZigzag(vector<int>& nums) {
    array<int, 2> rec{};
    for (int i = 0, n = nums.size(); i < n; i++) {
      int lhs = i - 1 >= 0 ? nums[i - 1] : numeric_limits<int>::max();
      int rhs = i + 1 < n ? nums[i + 1] : numeric_limits<int>::max();
      rec[i % 2] += max(0, nums[i] - min(lhs, rhs) + 1);
    }
    return min(rec[0], rec[1]);
  }
};
