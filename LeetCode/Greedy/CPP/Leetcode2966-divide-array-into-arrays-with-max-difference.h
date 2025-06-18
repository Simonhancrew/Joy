class Solution {
 public:
  vector<vector<int>> divideArray(vector<int> &nums, int k) {
    vector<vector<int>> res;
    ranges::sort(nums);
    int n = nums.size();
    res.reserve(n / 3);
    for (int i = 0; i < n; i += 3) {
      auto [x, y, z] = make_tuple(nums[i], nums[i + 1], nums[i + 2]);
      if (z - x > k) {
        return {};
      }
      res.push_back({x, y, z});
    }
    return res;
  }
};
