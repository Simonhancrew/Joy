#include <vector>

using namespace std;

class Solution {
 public:
  int captureForts(vector<int>& forts) {
    int ans = 0, n = forts.size();
    int pre = -1;
    for (int i = 0; i < n; i++) {
      if (forts[i] == 0) {
        continue;
      }
      if (pre >= 0 && forts[i] != forts[pre]) {
        ans = max(ans, i - pre - 1);
      }
      pre = i;
    }
    return ans;
  }
};
