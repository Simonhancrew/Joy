class Solution {
public:
  using LL = long long;
  long long maximumSubarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    LL acc = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      acc += nums[i];
      mp[nums[i]]++;
      if (i < k - 1)
        continue;
      if (mp.size() == k) {
        ans = max(ans, acc);
      }
      auto tar = nums[i - k + 1];
      acc -= tar;
      mp[tar]--;
      if (mp[tar] == 0)
        mp.erase(tar);
    }
    return ans;
  }
};
