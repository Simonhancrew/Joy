class Solution {
 public:
  typedef long long LL;
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int res = 0, n = nums.size();
    int acc = 1;
    for (int i = 0, j = 0; j < n; j++) {
      acc *= nums[j];
      while (i <= j && acc >= k) {
        acc /= nums[i];
        ++i;
      }
      res += j - i + 1;
    }
    return res;
  }
};