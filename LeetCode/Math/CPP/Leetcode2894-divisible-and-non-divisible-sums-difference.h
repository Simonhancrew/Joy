class Solution {
 public:
  int differenceOfSums(int n, int m) {
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
      if (i % m != 0)
        x += i;
      else if (i % m == 0)
        y += i;
    }
    return x - y;
  }
};
