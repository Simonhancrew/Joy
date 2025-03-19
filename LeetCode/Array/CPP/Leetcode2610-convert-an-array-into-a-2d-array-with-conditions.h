class Solution {
 public:
  vector<vector<int>> findMatrix(vector<int> &nums) {
    vector<int> cnt(nums.size() + 1);
    vector<vector<int>> res;
    for (const auto x : nums) {
      int &cur = cnt[x];
      if (cur == res.size()) {
        res.emplace_back();
      }
      res[cur].push_back(x);
      cur++;
    }
    return res;
  }
};
