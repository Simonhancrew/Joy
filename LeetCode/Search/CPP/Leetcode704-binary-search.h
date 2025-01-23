class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = -1, r = nums.size();
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (nums[mid] < target) {
        l = mid;
      } else {
        r = mid;
      }
    }
    if (r >= nums.size() || nums[r] != target) {
      return -1;
    }
    return r;
  }
};

