class Solution {
 public:
  bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> sub(n + 1, 0);
    for (const auto &q : queries) {
      int l = q[0], r = q[1];
      sub[l] += 1;
      sub[r + 1] -= 1;
    }
    for (int i = 0; i < n; i++) {
      sub[i] += (i == 0 ? 0 : sub[i - 1]);
      if (sub[i] < nums[i]) {
        return false;
      }
    }
    return true;
  }
};
