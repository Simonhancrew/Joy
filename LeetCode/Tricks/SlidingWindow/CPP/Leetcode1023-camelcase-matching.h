class Solution {
 public:
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    int n = queries.size();
    vector<bool> ans(n);
    auto check = [&pattern](const std::string& s) {
      if (pattern.size() > s.size()) return false;
      int j = 0;
      for (int i = 0; i < s.size(); i++) {
        if (j < pattern.size() && s[i] == pattern[j])
          j++;
        else if (isupper(s[i]))
          return false;
      }
      return j >= pattern.size();
    };
    for (int i = 0; i < n; i++) {
      ans[i] = check(queries[i]);
    }
    return ans;
  }
};
