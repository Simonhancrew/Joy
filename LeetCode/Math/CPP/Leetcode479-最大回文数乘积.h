class Solution {
 public:
  typedef long long LL;
  int largestPalindrome(int n) {
    if (n == 1) return 9;
    int base = pow(10, n) - 1;
    for (int left = base;; left--) {
      LL p = left;
      for (int x = left; x; x /= 10) {
        p = p * 10 + x % 10;
      }
      // cout << p << endl;
      for (int x = base; x >= p / x; x--) {
        if (p % x == 0) {
          return p % 1337;
        }
      }
    }
  }
};