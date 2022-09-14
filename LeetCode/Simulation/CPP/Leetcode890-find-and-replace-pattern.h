class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
    int n = pattern.size();
    vector<string> ans;
    for (auto &s : words) {
      if (s.size() != n) continue;
      vector<int> mp(26, -1), vis(26);
      bool ok = true;
      for (int i = 0; i < n && ok; i++) {
        int l = s[i] - 'a', r = pattern[i] - 'a';
        if (mp[l] == -1 && !vis[r]) {
          mp[l] = r;
          vis[r] = 1;
        } else if (mp[l] != r)
          ok = false;
      }
      if (ok) ans.push_back(s);
    }
    return ans;
  }
};