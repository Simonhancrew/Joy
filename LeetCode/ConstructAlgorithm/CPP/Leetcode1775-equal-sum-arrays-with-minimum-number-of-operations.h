class Solution {
 public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    if (6 * n < m || 6 * m < n) return -1;
    int s1 = accumulate(nums1.begin(), nums1.end(), 0), s2 = accumulate(nums2.begin(), nums2.end(), 0);
    int d = s1 - s2;
    if (d == 0) {
      return 0;
    }
    if (d < 0) {
      swap(nums1, nums2);
      swap(n, m);
      d = -d;
    }
    array<int, 6> cnt{};
    for(auto x : nums1) {
      cnt[x - 1]++;
    }
    for(auto x : nums2) {
      cnt[6 - x]++;
    }
    int ans = 0;
    for(int i = 5;i > 0;i--) {
      if (d - i * cnt[i] <= 0) {
        return ans + (d + i - 1) / i;
      }
      d -= i * cnt[i];
      ans += cnt[i];
    }
    return ans;
  }
};
