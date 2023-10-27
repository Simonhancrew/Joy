#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  static const int MOD = 1e9 + 7;
  using LL = long long;
  int maxArea(int h, int w, vector<int>& horizontalCuts,
              vector<int>& verticalCuts) {
    horizontalCuts.push_back(0);
    horizontalCuts.push_back(h);
    verticalCuts.push_back(0);
    verticalCuts.push_back(w);
    sort(verticalCuts.begin(), verticalCuts.end());
    sort(horizontalCuts.begin(), horizontalCuts.end());
    int n = horizontalCuts.size();
    int m = verticalCuts.size();
    int cur_h = 0;
    int cur_v = 0;
    for (int i = 1; i < n || i < m; i++) {
      if (i < n) {
        int diff = horizontalCuts[i] - horizontalCuts[i - 1];
        if (diff > cur_h) {
          cur_h = diff;
        }
      }
      if (i < m) {
        int diff = verticalCuts[i] - verticalCuts[i - 1];
        if (diff > cur_v) {
          cur_v = diff;
        }
      }
    }
    return (LL)cur_h * cur_v % MOD;
  }
};
