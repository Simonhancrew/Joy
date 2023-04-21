class Solution {
 public:
  int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

  int smallestEvenMultiple(int n) { return 2 * n / gcd(n, 2); }
};
