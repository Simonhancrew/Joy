class Solution {
 public:
  bool check(const string& lhs, const string& rhs) {
    if (lhs.length() + 1 != rhs.length()) return false;
    int n = rhs.size(), j = 0;
    for (int i = 0; i < n; i++) {
      if (lhs[j] == rhs[i]) j++;
      if (j == lhs.size()) return true;
    }
    return false;
  }

  int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(),
         [](auto& lhs, auto& rhs) { return lhs.size() < rhs.size(); });
    int n = words.size(), ans = 1;
    vector<int> f(n, 1);
    for (int i = 1; i < n; i++) {
      for (int j = i - 1; j >= 0 && words[j].size() + 1 >= words[i].size();
           j--) {
        if (check(words[j], words[i])) f[i] = max(f[i], f[j] + 1);
      }
      ans = max(ans, f[i]);
    }
    return ans;
  }
};
