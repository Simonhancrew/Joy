class Solution {
 public:
  bool is_odd(int x) {
    for (int i = 2; i <= x / i; i++) {
      if (x % i == 0) {
        return false;
      }
    }
    return x > 1;
  }
  int diagonalPrime(vector<vector<int>> &nums) {
    int res = 0, n = nums.size();
    for (int x = 0, y = 0, z = n - 1; x < n; x++, y++, z--) {
      if (is_odd(nums[x][y])) {
        res = max(res, nums[x][y]);
      }
      if (is_odd(nums[x][z])) {
        res = max(res, nums[x][z]);
      }
    }
    return res;
  }
};
