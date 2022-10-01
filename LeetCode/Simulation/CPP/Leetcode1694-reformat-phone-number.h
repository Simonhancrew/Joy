class Solution {
 public:
  string reformatNumber(string number) {
    string s;
    int n = number.size();
    for (int i = 0; i < n; i++) {
      if (number[i] == ' ' || number[i] == '-')
        continue;
      s += number[i];
    }
    n      = s.size();
    int hh = 0, tt = n - 1;
    string ans;
    while (tt - hh + 1 > 4) {
      if (ans.size())
        ans += "-";
      ans += s.substr(hh, 3);
      hh += 3;
    }
    if (tt - hh + 1 == 2 || tt - hh + 1 == 3) {
      if (ans.size())
        ans += "-";
      ans += s.substr(hh);
    } else {
      if (ans.size())
        ans += "-";
      ans += s.substr(hh, 2) + "-" + s.substr(hh + 2);
    }
    return ans;
  }
};