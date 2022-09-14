class Solution {
 public:
  int maxScore(string s) {
    int cnt_one = 0, n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') ++cnt_one;
    }
    int res = 0;
    for (int i = 0, lhs = 0, rhs = cnt_one; i < n - 1; i++) {
      if (s[i] == '0')
        lhs++;
      else
        rhs--;
      res = max(res, lhs + rhs);
    }
    return res;
  }
};