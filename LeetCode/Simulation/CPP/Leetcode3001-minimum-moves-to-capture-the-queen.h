#include <algorithm>

using namespace std;

class Solution {
 public:
  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    auto between = [](int a, int b, int c) {
      return min(a, c) < b && max(a, c) > b;
    };
    if (a == e && (c != e || !between(b, d, f))) {
      return 1;
    }
    if (b == f && (d != f || !between(a, c, e))) {
      return 1;
    }
    if (c + d == e + f && (a + b != e + f || !between(c, a, e))) {
      return 1;
    }
    if (c + 8 - d == e + 8 - f &&
        (a + 8 - b != e + 8 - f || !between(c, a, e))) {
      return 1;
    }
    return 2;
  }
};
