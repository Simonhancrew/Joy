class Solution {
 public:
  int maxRotateFunction(vector<int> &nums) {
    int acc = accumulate(nums.begin(), nums.end(), 0), res = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      res += i * nums[i];
    }
    int f = res;
    for (int i = n - 1; i >= 0; i--) {
      f += acc - n * nums[i];
      res = max(res, f);
    }
    return res;
  }
};