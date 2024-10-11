class Solution {
public:
  using LL = long long;
  long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size(), m = nums2.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      if (nums1[i] % k)
        continue;
      auto t = nums1[i] / k;
      for (int i = 1; i * i <= t; ++i) {
        if (t % i != 0)
          continue;
        mp[i]++;
        if (i * i < t) {
          mp[t / i]++;
        }
      }
    }
    LL ans = 0;
    for (const auto x : nums2) {
      if (mp.count(x)) {
        ans += mp[x];
      }
    }
    return ans;
  }
};
