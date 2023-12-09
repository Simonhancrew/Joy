#include <array>

using namespace std;

class Solution {
 public:
  int nextBeautifulNumber(int n) {
    auto check = [](int x) {
      array<int, 10> a{};
      while (x) {
        auto cur = x % 10;
        x /= 10;
        a[cur]++;
      }
      for (int i = 0; i < 10; i++) {
        if (a[i] && a[i] != i) return false;
      }
      return true;
    };
    for (int i = n + 1;; i++) {
      if (check(i)) {
        return i;
      }
    }
    return -1;
  }
};
