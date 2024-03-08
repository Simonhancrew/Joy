#include <algorithm>

using namespace std;

class Solution {
public:
  static constexpr int MOD = 1e9 + 7;
  int minimumPossibleSum(int n, int k) {
    int64_t m = min(k / 2, n);
    return (m * (m + 1) + (n - m - 1 + k * 2) * (n - m)) / 2 % MOD;
  }
};
