class Solution {
public:
  int minSubarray(vector<int>& nums, int p) {
    int n = nums.size(), x = 0;
    for (int i = 0;i < n;i++) {
      x = (x + nums[i]) % p;
    }
    if (x == 0) {
        return 0;
    }
    int y = 0, res = n;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0;i < n;i++) {
      y = (y + nums[i]) % p;
      int tar = (y - x +  p) % p;
      if (mp.count(tar)) {
        res = min(res, i - mp[tar]);
      }
      mp[y] = i;
    }
    return res == n ? -1 : res;
  }
};
