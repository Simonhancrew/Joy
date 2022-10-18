class Solution {
public:
  int m;
  vector<int> f;
  string s;
  vector<string> digits;
  int dfs(int idx, bool lead, bool limit) {
    if (idx == m)
      return !lead;
    if (!lead && !limit && f[idx] != -1)
      return f[idx];
    int res = 0;
    if (lead) {
      res = dfs(idx + 1, true, false);
    }
    char up = limit ? s[idx] : '9';
    for (string &d : digits) {
      if (d[0] > up)
        break;
      res += dfs(idx + 1, false, limit && d[0] == s[idx]);
    }
    if (!limit && !lead)
      f[idx] = res;
    return res;
  }

  int atMostNGivenDigitSet(vector<string> &digits, int n) {
    s = to_string(n);
    this->digits = digits;
    m = s.size();
    f.resize(m, -1);
    return dfs(0, true, true);
  }
};
