class Solution {
 public:
  using LL = long long;
  long long countAlternatingSubarrays(vector<int> &nums) {
    LL ans = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i && nums[i - 1] == nums[i]) {
        cnt = 0;
      }
      ans += ++cnt;
    }
    return ans;
  }
};
