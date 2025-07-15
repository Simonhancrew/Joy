class Solution {
 public:
  int maximumLength(vector<int> &nums) {
    int x{}, y{}, t{};
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] & 1)
        x++;
      else
        y++;
      if (nums[i] % 2 != nums[i + 1] % 2)
        t++;
    }
    if (nums[n - 1] & 1)
      x++;
    else
      y++;
    return max({t + 1, x, y});
  }
};
