class Solution {
public:
  int minOperations(vector<int> &nums) {
    int ans = 0, act = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] ^ act == 1)
        continue;
      act ^= 1;
      ans++;
    }
    return ans;
  }
};
