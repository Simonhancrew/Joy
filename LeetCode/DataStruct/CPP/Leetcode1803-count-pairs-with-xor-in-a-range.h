class Solution {
 public:
  int countPairs(vector<int>& nums, int low, int high) {
    int ans = 0;
    unordered_map<int, int> mp;
    for (auto num : nums) mp[num]++;
    for (++high; high; high >>= 1, low >>= 1) {
      unordered_map<int, int> tmp;
      for (auto& [k, v] : mp) {
        if ((high & 1) && mp.count(k ^ (high - 1))) ans += v * mp[k ^ (high - 1)];
        if (low & 1 && mp.count(k ^ (low - 1))) ans -= v * mp[k ^ (low - 1)];
        tmp[k >> 1] += v;
      }
      mp = move(tmp);
    }
    return ans / 2;
  }
};