class Solution {
 public:
  int maxDiff(int num) {
    auto s = to_string(num);
    for (const auto x : s) {
      if (x != '9') {
        ranges::replace(s, x, '9');
        break;
      }
    }
    int mx = stoi(s);
    s      = to_string(num);
    auto c = s[0];
    if (s[0] != '1') {
      ranges::replace(s, c, '1');
    } else {
      for (const auto x : s) {
        if (x > '1') {
          ranges::replace(s, x, '0');
          break;
        }
      }
    }
    int mn = stoi(s);
    return mx - mn;
  }
};
