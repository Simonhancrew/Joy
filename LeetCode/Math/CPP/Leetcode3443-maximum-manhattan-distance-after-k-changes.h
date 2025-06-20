class Solution {
 public:
  int maxDistance(string s, int k) {
    int mp['x']{};
    int res = 0;
    auto f  = [](int a, int b, int &remain) {
      int d = min({a, b, remain});
      remain -= d;
      return abs(a - b) + 2 * d;
    };
    for (const auto c : s) {
      mp[c]++;
      int remain = k;
      res =
          max({res, f(mp['N'], mp['S'], remain) + f(mp['E'], mp['W'], remain)});
    }
    return res;
  }
};