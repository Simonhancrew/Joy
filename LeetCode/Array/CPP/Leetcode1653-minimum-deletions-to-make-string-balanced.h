class Solution {
 public:
  int minimumDeletions(string s) {
    int n = s.size();
    vector<int> s1(n + 1), s2(n + 1);
    for (int i = 1; i <= n; i++) {
      s1[i] = s1[i - 1];
      s2[i] = s2[i - 1];
      if (s[i - 1] == 'a')
        s1[i]++;
      else
        s2[i]++;
    }
    int res = numeric_limits<int>::max();
    for (int i = 0; i <= n; i++) {
      res = min(res, s2[i] + s1[n] - s1[i]);
    }
    return res;
  }
};
