class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n < 0) {
      return false;
    }
    int l = -1, r = 21;
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (pow(3, mid) <= n)
        l = mid;
      else
        r = mid;
    }
    return pow(3, l) == n;
  }
};
