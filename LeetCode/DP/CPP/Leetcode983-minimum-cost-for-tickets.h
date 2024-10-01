class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    auto last_day = days.back();
    unordered_set<int> st(days.begin(), days.end());
    vector<int> f(last_day + 1, -1);
    auto dfs = [&](auto &&dfs, int i) {
      if (i <= 0) {
        return 0;
      }
      auto &ans = f[i];
      if (ans != -1) {
        return ans;
      }
      ans = 0;
      if (!st.contains(i)) {
        return ans = dfs(dfs, i - 1);
      }
      return (ans = min({dfs(dfs, i - 1) + costs[0], dfs(dfs, i - 7) + costs[1],
                         dfs(dfs, i - 30) + costs[2]}));
    };
    return dfs(dfs, last_day);
  }
};
