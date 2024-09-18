class Solution {
public:
  using LL = long long;
  long long maxSum(vector<int> &nums, int m, int k) {
    unordered_map<int, int> mp;
    LL acc = 0;
    LL ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      mp[nums[i]]++;
      acc += nums[i];
      if (i < k - 1)
        continue;
      auto sz = mp.size();
      if (sz >= m)
        ans = max(ans, acc);
      auto del = nums[i - k + 1];
      acc -= del;
      mp[del]--;
      if (mp[del] == 0) {
        mp.erase(del);
      }
    }
    return ans;
  }
};
