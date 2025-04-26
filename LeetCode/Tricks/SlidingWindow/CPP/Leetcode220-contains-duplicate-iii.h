class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff,
                                     int valueDiff) {
    map<int, int> mp;
    int l = 0, n = nums.size();
    for (int r = 0; r < n; ++r) {
      auto lower = nums[r] - valueDiff;
      auto iter  = mp.lower_bound(lower);
      if (iter != mp.end() && iter->first <= nums[r] + valueDiff) {
        return true;
      }
      mp[nums[r]]++;
      if (r >= indexDiff) {
        auto tar = nums[l++];
        if (--mp[tar] == 0) {
          mp.erase(tar);
        }
      }
    }
    return false;
  }
};
