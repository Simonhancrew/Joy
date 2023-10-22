#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end(),
         [](int l, int r) { return l > r; });
    int sum = 0;
    int ans = 0;
    int n = satisfaction.size();
    for (int i = 0; i < n; i++) {
      sum += satisfaction[i];
      if (sum < 0) break;
      ans += sum;
    }
    return ans;
  }
};
