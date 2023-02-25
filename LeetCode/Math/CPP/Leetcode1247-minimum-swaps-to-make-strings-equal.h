class Solution {
 public:
  int minimumSwap(string s1, string s2) {
    int a{}, b{};
    for (int i = 0, n = s1.size(); i < n; i++) {
      if (s1[i] != s2[i]) {
        if (s1[i] == 'x')
          a++;
        else
          b++;
      }
    }
    if ((a + b) % 2) return -1;
    return a / 2 + b / 2 + a % 2 + b % 2;
  }
};