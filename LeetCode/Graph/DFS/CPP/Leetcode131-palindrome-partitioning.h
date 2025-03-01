class Solution {
 public:
  bool check(string &s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r]) {
        return false;
      }
      l++, r--;
    }
    return true;
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> cur;
    int n    = s.size();
    auto dfs = [&](auto &&dfs, int i) {
      if (i == n) {
        res.emplace_back(cur);
        return;
      }
      for (int j = i; j < n; ++j) {
        if (check(s, i, j)) {
          cur.push_back(s.substr(i, j - i + 1));
          dfs(dfs, j + 1);
          cur.pop_back();
        }
      }
    };
    dfs(dfs, 0);
    return res;
  }
};
