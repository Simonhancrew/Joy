#include <vector>

using namespace std;

class Solution {
 public:
  int largestCombination(vector<int> &candidates) {
    int ans = 0;
    for (int i = 0; i < 25; i++) {
      int cur = 0;
      for (const auto x : candidates) {
        if ((1 << i) & x) {
          ++cur;
        }
      }
      ans = max(ans, cur);
    }
    return ans;
  }
};
