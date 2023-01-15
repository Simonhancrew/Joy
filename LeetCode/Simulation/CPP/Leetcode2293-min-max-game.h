class Solution {
 public:
  int minMaxGame(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return nums.back();
    }
    int len = n / 2;
    while (len) {
      vector<int> arr(len);
      for (int i = 0; i < len; i++) {
        if (i & 1)
          arr[i] = max(nums[2 * i], nums[2 * i + 1]);
        else
          arr[i] = min(nums[i * 2], nums[2 * i + 1]);
      }
      nums = std::move(arr);
      len /= 2;
    }
    return nums.back();
  }
};