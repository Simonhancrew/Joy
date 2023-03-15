class Solution {
 public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<unordered_set<int>> g(n);
    for (const auto& r : roads) {
      g[r[0]].insert(r[1]);
      g[r[1]].insert(r[0]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int cur = g[i].size() + g[j].size();
        if (g[i].count(j)) {
          cur--;
        }
        if (ans < cur) {
          ans = cur;
        }
      }
    }
    return ans;
  }
};
