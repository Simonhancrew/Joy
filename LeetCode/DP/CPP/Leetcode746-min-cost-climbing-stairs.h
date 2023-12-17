#include <vector>

using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> f(3);
    f[1] = 0, f[2] = 0;
    for (int i = 2; i <= n; i++) {
      f[i % 3] =
          min(f[(i - 1) % 3] + cost[i - 1], f[(i - 2 + 3) % 3] + cost[i - 2]);
    }
    return f[n % 3];
  }
};
