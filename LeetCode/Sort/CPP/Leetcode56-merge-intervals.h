class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    ranges::sort(intervals);
    vector<vector<int>> ans;
    for (auto &x : intervals) {
      if (!ans.empty() && ans.back()[1] >= x[0]) {
        ans.back()[1] = max(ans.back()[1], x[1]);
      } else {
        ans.push_back(move(x));
      }
    }
    return ans;
  }
};
