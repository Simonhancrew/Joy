class Solution {
 public:
  bool validPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    auto check = [&](auto &&check, int l, int r, int cnt) {
      if (l >= r) {
        return true;
      }
      if (s[l] == s[r]) {
        return check(check, l + 1, r - 1, cnt);
      }
      if (!cnt) {
        return false;
      }
      return check(check, l + 1, r, 0) || check(check, l, r - 1, 0);
    };
    return check(check, l, r, 1);
  }
};
