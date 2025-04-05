class Solution {
 public:
  int subsetXORSum(vector<int> &nums) {
    int sum = 0, n = nums.size();
    auto dfs = [&](this auto &&dfs, int i, int acc) {
      if (i >= n) {
        sum += acc;
        return;
      }
      dfs(i + 1, acc ^ nums[i]);
      dfs(i + 1, acc);
    };
    dfs(0, 0);
    return sum;
  }
};
