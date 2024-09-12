class Solution {
 public:
  int maxNumOfMarkedIndices(vector<int>& nums) {
    ranges::sort(nums);
    int l = -1, r = nums.size() / 2 + 1;
    auto check = [&](int k) {
      for (int i = 0; i < k; i++) {
        if (nums[i] * 2 > nums[nums.size() - k + i]) {
          return false;
        }
      }
      return true;
    };
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    return 2 * l;
  }
};
