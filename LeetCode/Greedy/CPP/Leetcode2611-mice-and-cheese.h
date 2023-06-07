#include <vector>

using namespace std;

class Solution {
 public:
  using PII = pair<int, int>;
  int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    int n = reward1.size(), ans = 0;
    vector<int> diff;
    for (int i = 0; i < n; i++) {
      ans += reward2[i];
      diff.emplace_back(reward1[i] - reward2[i]);
    }
    sort(diff.begin(), diff.end(),
         [](auto& lhs, auto& rhs) { return lhs > rhs; });
    int idx = 0;
    while (k--) {
      ans += diff[idx++];
    }
    return ans;
  }
};
