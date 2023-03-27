class Solution {
 public:
  bool diff1(int l, int r, const string& s, const string& t, int ll) {
    int flag = false;
    for (int i = l, j = ll; i <= r; i++, j++) {
      if (s[i] != t[j]) {
        if (flag) return false;
        flag = true;
      }
    }
    return flag;
  }

  int calcu(int l, int r, const std::string& s, const std::string& t) {
    int n = t.size();
    int cnt = 0;
    for (int i = 0; i < n - (r - l); i++) {
      cnt += diff1(l, r, s, t, i);
    }
    return cnt;
  }

  int countSubstrings(string s, string t) {
    int cnt = 0, n = s.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        cnt += calcu(i, j, s, t);
      }
    }
    return cnt;
  }
};