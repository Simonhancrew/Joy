class Solution {
 public:
  vector<string> ambiguousCoordinates(string s) {
    int n = s.size();
    vector<string> res;
    auto get = [](const string &s) {
      vector<string> ans;
      if (s.size() == 1 || s[0] != '0') ans.push_back(s);
      for (int i = 1; i < s.size(); i++) {
        auto lhs = s.substr(0, i), rhs = s.substr(i);
        if (lhs.size() > 1 && lhs[0] == '0') continue;
        if (rhs.back() == '0') continue;
        ans.emplace_back(lhs + '.' + rhs);
      }
      return ans;
    };
    s = s.substr(1, n - 2);
    for (int i = 1; i < s.size(); i++) {
      auto l = get(s.substr(0, i)), r = get(s.substr(i));
      for (auto &x : l) {
        for (auto &y : r) {
          res.push_back(('(' + x + ", " + y + ')'));
        }
      }
    }
    return res;
  }
};
