class Solution {
 public:
  using LL = long long;
  long long countSubarrays(vector<int> &nums, int k) {
    int n = nums.size(), cnt = 0;
    auto tar = *max_element(nums.begin(), nums.end());
    LL ans   = 0;
    for (int r = 0, l = 0; r < n; ++r) {
      if (nums[r] == tar)
        ++cnt;
      while (cnt >= k && l <= r) {
        if (nums[l] == tar) {
          cnt--;
        }
        l++;
      }
      ans += l;
    }
    return ans;
  }
};
