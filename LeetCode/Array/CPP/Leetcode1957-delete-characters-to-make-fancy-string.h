class Solution {
 public:
  string makeFancyString(string s) {
    if (s.size() < 3) {
      return move(s);
    }
    string res(s.begin(), s.begin() + 2);
    for (int i = 2; i < s.size(); i++) {
      if (s[i] == res.back() && s[i] == res[res.size() - 2]) {
        continue;
      }
      res.push_back(s[i]);
    }
    return res;
  }
};
