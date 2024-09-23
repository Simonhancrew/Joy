#include <vector>

using namespace std;

class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int mx = values[0] + 0;
    int n = values.size();
    int ans = 0, cur = 0;
    for (int i = 1; i < n; i++) {
      cur = mx + values[i] - i;
      if (cur > ans) {
        ans = cur;
      }
      if (mx < values[i] + i) {
        mx = values[i] + i;
      }
    }
    return ans;
  }
};
