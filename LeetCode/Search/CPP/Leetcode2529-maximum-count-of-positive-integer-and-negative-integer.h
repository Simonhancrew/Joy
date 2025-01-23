class Solution {
 public:
  int maximumCount(vector<int>& nums) {
    int l = -1, r = nums.size();
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (nums[mid] < 0) {
        l = mid;
      } else {
        r = mid;
      }
    }
    auto lhs = r;
    l = -1, r = nums.size();
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (nums[mid] <= 0) {
        l = mid;
      } else {
        r = mid;
      }
    }
    auto rhs = r;
    int positive = nums.size() - rhs;
    int nagtive = lhs;
    return max(nagtive, positive);
  }
};

