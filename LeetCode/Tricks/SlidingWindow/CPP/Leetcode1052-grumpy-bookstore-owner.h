#include <vector>

using namespace std;

class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    int n = customers.size();
    int acc = 0;
    for (int i = 0; i < n; i++) {
      if (grumpy[i] == 0)
        acc += customers[i];
    }
    int ans = acc;
    for (int i = 0; i < n; i++) {
      if (grumpy[i] == 1)
        acc += customers[i];
      if (i < minutes - 1)
        continue;
      ans = max(ans, acc);
      auto tar = i - minutes + 1;
      if (grumpy[tar] == 1)
        acc -= customers[tar];
    }
    return ans;
  }
};
