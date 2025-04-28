class Solution {
 public:
  using LL = long long;
  long long countSubarrays(vector<int> &nums, long long k) {
    int n  = nums.size();
    LL acc = 0, ans = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      acc += nums[r];
      while (l <= r && acc * (r - l + 1) >= k) {
        acc -= nums[l++];
      }
      ans += r - l + 1;
    }
    return ans;
  }
};
