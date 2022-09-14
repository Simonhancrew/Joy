class Solution {
 public:
  string reformat(string s) {
    vector<char> dc, sc;
    for (auto c : s) {
      if (isdigit(c))
        dc.push_back(c);
      else
        sc.push_back(c);
    }
    int a = dc.size(), b = sc.size();
    if (!a && b > 1 || !b && a > 1) return "";
    if (abs(a - b) >= 2) return "";
    string ans;
    if (dc.size() > sc.size()) swap(dc, sc);
    for (int i = 0, id = 0, is = 0; i < s.size(); i++) {
      if (i & 1)
        ans += dc[id++];
      else
        ans += sc[is++];
    }
    return ans;
  }
};