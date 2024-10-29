class Solution {
public:
  vector<string> validStrings(int n) {
    vector<string> ans;
    string s(n, 0);
    auto dfs = [&s, &ans, n](auto &&dfs, int i) {
      if (i == n) {
        ans.push_back(s);
        return;
      }
      if (i == 0) {
        s[i] = '0';
        dfs(dfs, i + 1);
        s[0] = '1';
        dfs(dfs, i + 1);
        return;
      }
      if (s[i - 1] == '0') {
        s[i] = '1';
        dfs(dfs, i + 1);
        return;
      }
      s[i] = '0';
      dfs(dfs, i + 1);
      s[i] = '1';
      dfs(dfs, i + 1);
    };
    dfs(dfs, 0);
    return ans;
  }
};
