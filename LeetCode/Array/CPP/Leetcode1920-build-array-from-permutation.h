class Solution {
 public:
  vector<int> buildArray(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0) {
        continue;
      }
      int x   = nums[i];
      int cur = i;
      while (nums[cur] != i) {
        int ne    = nums[cur];
        nums[cur] = ~nums[ne];
        cur       = ne;
      }
      nums[cur] = ~x;
    }
    for (int i = 0; i < nums.size(); ++i) {
      nums[i] = ~nums[i];
    }
    return move(nums);
  }
};
