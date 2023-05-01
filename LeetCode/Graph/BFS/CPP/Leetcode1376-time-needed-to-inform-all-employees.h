class Solution {
 public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    vector<vector<int>> mp(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
      if (manager[i] == -1)
        root = i;
      else {
        int fa = manager[i], cur = i;
        mp[fa].push_back(cur);
      }
    }
    std::function<int(int)> dfs = [&mp, &informTime, &dfs](int x) {
      if (mp[x].empty()) return 0;
      int cost = informTime[x], n = mp[x].size();
      int mx = 0;
      for (int i = 0; i < n; i++) {
        mx = max(mx, dfs(mp[x][i]));
      }
      return cost + mx;
    };
    return dfs(root);
  }
};