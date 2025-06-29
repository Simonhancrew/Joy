class Solution {
 public:
  static constexpr int MOD = 1e9 + 7;
  using LL                 = long long;
  int qpow(int x) {
    int base = 2, res = 1;
    while (x) {
      if (x & 1) {
        res = ((LL)res * base) % MOD;
      }
      base = ((LL)base * base) % MOD;
      x >>= 1;
    }
    return res;
  }
  int numSubseq(vector<int> &nums, int target) {
    ranges::sort(nums);
    int n = nums.size();
    int l = 0, r = n - 1;
    int res = 0;
    while (l <= r) {
      if (nums[l] + nums[r] <= target) {
        res = ((LL)res + qpow(r - l)) % MOD;
        l++;
      } else {
        r--;
      }
    }
    return res;
  }
};
