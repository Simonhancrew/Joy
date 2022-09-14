class Solution {
 public:
  int maximumWealth(vector<vector<int>> &accounts) {
    int mx = 0;
    for (auto &x : accounts) {
      int cur = accumulate(x.begin(), x.end(), 0);
      mx = max(mx, cur);
    }
    return mx;
  }
};