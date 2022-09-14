class Solution {
 public:
  bool hasAlternatingBits(int n) {
    int pre = n & 1;
    n >>= 1;
    while (n) {
      if (n & 1) {
        if (pre) return false;
        pre = n & 1;
      } else {
        if (!pre) return false;
        pre = n & 1;
      }
      n >>= 1;
    }
    return true;
  }
};