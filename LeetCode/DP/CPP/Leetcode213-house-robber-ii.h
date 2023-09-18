class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return nums.back();
    }
    vector<int> f(n);
    // 选0，不能选1和n - 1，等价在[2, n - 2]上做打家劫舍，然后+0的值
    for (int i = 2; i < n - 1; i++) {
      f[i] = max(f[i - 1], f[i - 2] + nums[i]);
    }
    // 不选1， 可以选[1, n - 1], 等价在[1, n - 1]上做打家劫舍
    int res = nums[0] + f[n - 2];
    for (int i = 1; i < n; i++) {
      f[i] = max(f[i - 1], (i >= 2 ? f[i - 2] : 0) + nums[i]);
    }
    res = max(res, f[n - 1]);
    return res;
  }
};
