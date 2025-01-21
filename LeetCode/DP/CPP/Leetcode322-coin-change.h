#include <functional>
#include <vector>


using namespace std;

class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> f(amount + 1, 0x3f3f3f3f);
    f[0] = 0;
    for (const auto x : coins) {
      if (x >= amount)
        continue;
      f[x] = 1;
    }
    for (int i = 0; i <= amount; i++) {
      for (const auto x : coins) {
        if (i >= x) {
          f[i] = min(f[i], f[i - x] + 1);
        }
      }
    }
    return f[amount] == 0x3f3f3f3f ? -1 : f[amount];
  }
};