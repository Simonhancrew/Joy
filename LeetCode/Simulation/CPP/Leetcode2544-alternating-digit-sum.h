class Solution {
 public:
  int alternateDigitSum(int n) {
    string s = to_string(n);
    n = s.size();
    int ans = 0, pos = 1;
    for (int i = 0; i < n; i++) {
      ans += pos * (s[i] - '0');
      pos *= -1;
    }
    return ans;
  }
};
