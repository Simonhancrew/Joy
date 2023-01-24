class Solution {
 public:
  vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
    vector<int> ans;
    auto get = [](const vector<vector<int>>& st, const vector<int>& q) {
      int res = 0;
      int x = q[0], y = q[1], r = q[2];
      for (auto p : st) {
        if ((x - p[0]) * (x - p[0]) + (y - p[1]) * (y - p[1]) <= r * r) {
          res++;
        }
      }
      return res;
    };
    for (const auto& q : queries) {
      ans.emplace_back(get(points, q));
    }
    return ans;
  }
};