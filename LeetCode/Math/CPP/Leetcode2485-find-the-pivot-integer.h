#include <vector>

using namespace std;

class Solution {
 public:
  int pivotInteger(int n) {
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] + i;
    }
    for (int i = 1; i <= n; i++) {
      if (p[i] - p[0] == p[n] - p[i - 1]) {
        return i;
      }
    }
    return -1;
  }
};
