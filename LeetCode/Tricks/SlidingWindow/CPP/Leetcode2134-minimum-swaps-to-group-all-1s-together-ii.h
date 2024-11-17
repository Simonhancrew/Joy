class Solution {
 public:
  int minSwaps(vector<int> &nums) {
    int k = accumulate(nums.begin(), nums.end(), 0);
    if (k <= 1) {
      return 0;
    }
    nums.insert(nums.end(), nums.begin(), nums.end());
    int cnt = 0, n = nums.size();
    int ans = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
      cnt += (nums[i] == 0);
      if (i < k - 1)
        continue;
      ans = min(ans, cnt);
      cnt -= (nums[i - k + 1] == 0);
    }
    return ans;
  }
};
